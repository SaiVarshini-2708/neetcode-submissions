class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>=2){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x>y){
                pq.push(x-y);
            }
            else if(y>x){
                pq.push(y-x);
            }
        }

      if (!pq.empty())
            return pq.top();

        return 0;
       
        
    }
};
