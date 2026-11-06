class Solution {
public:
    std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
        int q_size = queries.size();
        std::vector<int> ans(q_size);
    
        std::vector<int> count(n + 1, 0);
        
        std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        
        std::vector<std::pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        std::sort(sorted_queries.begin(), sorted_queries.end());
        
        int i = 0; 
        int j = 0; 
        int active_servers = 0;
        
        for (const auto& [query, queryIndex] : sorted_queries) {
            while (j < logs.size() && logs[j][1] <= query) {
                int server_id = logs[j][0];
                if (count[server_id] == 0) {
                    active_servers++;
                }
                count[server_id]++;
                j++;
            }
            
            while (i < logs.size() && logs[i][1] < query - x) {
                int server_id = logs[i][0];
                count[server_id]--;
                if (count[server_id] == 0) {
                    active_servers--;
                }
                i++;
            }
            
            ans[queryIndex] = n - active_servers;
        }
        
        return ans;
    }
};
