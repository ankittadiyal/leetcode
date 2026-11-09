class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> idle;
        for (int i = 0; i < k; ++i) {
            idle.insert(i);
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            long long currTime = arrival[i];
            
            // Free up servers that have completed their requests
            while (!busy.empty() && busy.top().first <= currTime) {
                idle.insert(busy.top().second);
                busy.pop();
            }
            
            if (idle.empty()) {
                continue; // All servers are busy, drop request
            }
            
            // Find the first available server >= (i % k)
            auto it = idle.lower_bound(i % k);
            if (it == idle.end()) {
                it = idle.begin(); // Wrap around to index 0
            }
            
            int server = *it;
            idle.erase(it);
            
            busy.push({currTime + load[i], server});
            count[server]++;
        }
        
        int maxCount = 0;
        for (int c : count) {
            maxCount = max(maxCount, c);
        }
        
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxCount) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
