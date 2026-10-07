class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;i++){
            pq.push({(points[i][0]*points[i][0]+points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        int size=pq.size();
        int i=0;
        vector<vector<int>>ans(size, vector<int>(2));
        while(!pq.empty()){
           int x=pq.top().second.first;
           int y=pq.top().second.second;
           ans[i][0]=x;
           ans[i][1]=y;
           i++;
           pq.pop();
        }

        return ans;

    }
};
