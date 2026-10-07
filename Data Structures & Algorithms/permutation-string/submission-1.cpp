class Solution {
public:
bool allZeros(unordered_map<char,int>&mp){
    for(auto it:mp){
        if(it.second!=0){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s1[i]]++;
        }
        int l=0;
        int r=0;
        while(r<s2.size()){
            if(mp.find(s2[r])!=mp.end()){
                 mp[s2[r]]--;
            }
            if((r-l+1)==n){
                if(allZeros(mp)){
                    return true;
                }
                if(mp.find(s2[l])!=mp.end()){
                mp[s2[l]]++;
            }
            l++;
            }

            r++;
            
        }

        return false;
    }
};
