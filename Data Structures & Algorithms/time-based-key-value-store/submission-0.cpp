class TimeMap {
public:
map<string,vector<pair<int,string>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
         if (mp.find(key) == mp.end()) {
            return "";
        }

        auto &temp = mp[key];
        int l = 0;
        int h = temp.size() - 1;
        string ans = "";
        while(l<=h){
            int mid=l+(h-l)/2;
            if(temp[mid].first<=timestamp){
                ans=temp[mid].second;
               l=mid+1;
            }
            else{
                h=mid-1;
            }
        }

        return ans;
    }
};
