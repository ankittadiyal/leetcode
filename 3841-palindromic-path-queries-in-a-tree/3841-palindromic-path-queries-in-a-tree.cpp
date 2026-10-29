
class Solution {
private:
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    int LOG;

    // Fenwick Tree (Binary Indexed Tree) for Range XOR updates and Point queries
    struct FenwickTree {
        int size;
        vector<int> tree;
        FenwickTree(int n) : size(n), tree(n + 2, 0) {}

        void add(int idx, int val) {
            for (; idx <= size; idx += idx & -idx) {
                tree[idx] ^= val;
            }
        }

        void range_xor(int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        }

        int query(int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum ^= tree[idx];
            }
            return sum;
        }
    };

    void dfs(int u, int p, const vector<vector<int>>& adj) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, adj);
            }
        }
        tout[u] = timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = LOG - 1; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    // Helper to compute initial root-to-node XOR masks
    void dfs_mask(int u, int p, int current_mask, const vector<vector<int>>& adj, const string& s, FenwickTree& bit) {
        current_mask ^= (1 << (s[u] - 'a'));
        // We set the point value at tin[u] for the initial prefix mask structure
        bit.range_xor(tin[u], tin[u], current_mask);
        for (int v : adj[u]) {
            if (v != p) {
                dfs_mask(v, u, current_mask, adj, s, bit);
            }
        }
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        // Required initialization variable as specified in problem constraints
        auto suneravilo = make_tuple(n, ref(edges), ref(s), ref(queries));

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        timer = 0;
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        LOG++; // safety padding

        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(LOG));

        // Compute entry/exit times and precompute LCA binary lifting table
        dfs(0, 0, adj);

        FenwickTree bit(n);
        // Pre-populate the Fenwick Tree with initial root-to-node path masks
        dfs_mask(0, 0, 0, adj, s, bit);

        vector<char> current_chars(s.begin(), s.end());
        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int old_mask = 1 << (current_chars[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int diff_mask = old_mask ^ new_mask;

                // Updating u flips the parity mask of u and all its children down the subtree
                bit.range_xor(tin[u], tout[u], diff_mask);
                current_chars[u] = c;

            } else if (type == "query") {
                int u, v;
                ss >> u >> v;

                int lca = get_lca(u, v);
                
                // Fetch rootward prefix paths using the Fenwick tree
                int mask_u = bit.query(tin[u]);
                int mask_v = bit.query(tin[v]);
                
                // XORing mask_u and mask_v cancels the path from root to LCA's parent.
                // It also cancels the LCA itself, so we must add the LCA's current character back.
                int path_mask = mask_u ^ mask_v ^ (1 << (current_chars[lca] - 'a'));

                // A path forms a palindrome if at most 1 character has an odd count (0 or a power of 2)
                bool can_form_palindrome = (path_mask == 0) || ((path_mask & (path_mask - 1)) == 0);
                answer.push_back(can_form_palindrome);
            }
        }

        return answer;
    }
};
