class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;
        }

        int need = t.size();

        int l = 0;
        int ansStart = 0;
        int ansLen = INT_MAX;

        for(int r = 0; r < s.size(); r++) {

            // Add s[r]
            if(mp[s[r]] > 0) {
                need--;
            }

            mp[s[r]]--;

            // Window is valid
            while(need == 0) {

                // Update minimum answer
                if(r - l + 1 < ansLen) {
                    ansLen = r - l + 1;
                    ansStart = l;
                }

                // Remove s[l]
                mp[s[l]]++;

                // We just removed a required character
                if(mp[s[l]] > 0) {
                    need++;
                }

                l++;
            }
        }

        if(ansLen == INT_MAX)
            return "";

        return s.substr(ansStart, ansLen);
    }
};