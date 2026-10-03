class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize!=0) return false;
        sort(hand.begin(),hand.end());
        vector<int>vis(n,0);
        int count=n;
         
        for(int i=0;i<=n-groupSize;i++){
           
            if(count==0) return true;
            if(vis[i]==1) continue;
            int temp=1;
            count--;
            vis[i]=1;
            for(int j= i+1;j<n;j++){
                if(vis[j]==1) continue;
                if(hand[i]+temp==hand[j]){ 
                    temp++;
                    count--;
                    vis[j]=1;
                }
                // else{
                //     continue;
                // }
                if(temp==groupSize) break;
           }
           if(temp<groupSize) return false;
        }
        return true;
    }
};
