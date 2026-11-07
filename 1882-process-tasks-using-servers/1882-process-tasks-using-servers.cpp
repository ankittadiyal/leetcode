class Solution {
public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
        // free: stores {weight, index}
        // Element with smallest weight (then smallest index) is on top
        using FreeServer = std::pair<int, int>;
        std::priority_queue<FreeServer, std::vector<FreeServer>, std::greater<FreeServer>> free;
        
        // used: stores {freeTime, weight, index}
        // Element with earliest freeTime (then smallest weight/index) is on top
        using UsedServer = std::tuple<long long, int, int>;
        std::priority_queue<UsedServer, std::vector<UsedServer>, std::greater<UsedServer>> used;
        
        // Initialize all servers as free at time 0
        for (int i = 0; i < servers.size(); ++i) {
            free.push({servers[i], i});
        }
        
        std::vector<int> ans;
        long long currTime = 0;
        
        for (int i = 0; i < tasks.size(); ++i) {
            // Virtual time tracks the max of current task availability index or simulation timeline
            currTime = std::max(currTime, static_cast<long long>(i));
            
            // If no servers are available, jump time directly to the earliest release time
            if (free.empty() && !used.empty()) {
                currTime = std::get<0>(used.top());
            }
            
            // Release all servers that finished processing at or before currTime
            while (!used.empty() && std::get<0>(used.top()) <= currTime) {
                auto [freeTime, weight, idx] = used.top();
                used.pop();
                free.push({weight, idx});
            }
            
            // Assign the task to the best available free server
            auto [weight, idx] = free.top();
            free.pop();
            
            ans.push_back(idx);
            used.push({currTime + tasks[i], weight, idx});
        }
        
        return ans;
    }
};
