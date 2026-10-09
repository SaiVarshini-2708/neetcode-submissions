class Solution {
public:
bool check(vector<int>& piles, int h,int k){
    long long total=0;
    for(int i=0;i<piles.size();i++){
        total += (piles[i] + k - 1) / k;
    }
    return total<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=1e9;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
