class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        pq.push({dist[0][1] = 0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, consec] = pq.top(); pq.pop();
            if (u == n - 1) return d;
            if (d > dist[u][consec]) continue;

            for (auto& [v, w] : adj[u]) {
                int next_c = (labels[u] == labels[v]) ? consec + 1 : 1;
                if (next_c <= k && d + w < dist[v][next_c]) {
                    pq.push({dist[v][next_c] = d + w, v, next_c});
                }
            }
        }
        return -1;
    }
};