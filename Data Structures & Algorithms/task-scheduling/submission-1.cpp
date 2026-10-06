class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);

        for (char &ch : tasks) {
            mp[ch - 'A']++;
        }

        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) {
            if (mp[i] > 0) {
                pq.push(mp[i]);
            }
        }

        int time = 0;

        while (!pq.empty()) {
            vector<int> temp;

            // One cycle = n + 1 slots
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();

                    freq--;
                    temp.push_back(freq);
                }
            }

            // Put remaining frequencies back
            for (int f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            // If tasks remain, we need the full n+1 cycle.
            // Otherwise, only count the tasks actually executed.
            if (!pq.empty()) {
                time += n + 1;
            } else {
                time += temp.size();
            }
        }

        return time;
    }
};