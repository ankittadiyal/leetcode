class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        const int arriveA = toDays(arriveAlice);
        const int leaveA = toDays(leaveAlice);
        const int arriveB = toDays(arriveBob);
        const int leaveB = toDays(leaveBob);
        
        // The overlap starts at the latest arrival and ends at the earliest departure
        int startOverlap = max(arriveA, arriveB);
        int endOverlap = min(leaveA, leaveB);
        
        return max(0, endOverlap - startOverlap + 1);
    }

private:
    const vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int toDays(const string& s) {
        int month = stoi(s.substr(0, 2));
        int day = stoi(s.substr(3, 2));
        int totalDays = day;
        for (int m = 1; m < month; ++m) {
            totalDays += days[m];
        }
        return totalDays;
    }
};
