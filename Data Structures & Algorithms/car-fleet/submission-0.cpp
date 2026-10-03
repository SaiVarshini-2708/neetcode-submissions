class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        
        vector<double>st;
        unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[position[i]]=speed[i];
    }
    sort(position.begin(),position.end());
    for(int i=n-1;i>=0;i--){
     double time=(double)(target-position[i])/mp[position[i]];
     if(st.empty()|| time>st.back()){
           st.push_back(time);
     }
     else{
        continue;
     }
    }

    return st.size();

    }
};
