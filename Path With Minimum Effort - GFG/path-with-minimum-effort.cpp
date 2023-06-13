//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> distance(n, vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        

        while (!pq.empty()){
            auto it = pq.top(); pq.pop();
            int minAbs = it.first;
            int r = it.second.first;
            int c = it.second.second;
            int row[4] = {-1,0,1,0};
            int col[4] = {0,1,0,-1};
            
            for (int i = 0; i < 4; i++) {
    int rnew = r + row[i];
    int cnew = c + col[i];
    if (rnew >= 0 && cnew >= 0 && rnew < n && cnew < m) {
        int dis = abs(heights[rnew][cnew] - heights[r][c]);
        if (distance[rnew][cnew] > max(dis, distance[r][c])) {
            distance[rnew][cnew] = max(dis, distance[r][c]);
            pq.push({ distance[rnew][cnew], { rnew, cnew } });
        }
    }
}

        }
        if (distance[n-1][m-1] != 1e9) return distance[n-1][m-1];
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends