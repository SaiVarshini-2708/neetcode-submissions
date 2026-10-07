class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minele=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){
            minele=min(minele,prices[i]);
            profit=max(profit,prices[i]-minele);
        }

        return profit;
        
    }
};
