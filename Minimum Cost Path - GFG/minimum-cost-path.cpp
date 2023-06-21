//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	typedef pair<int, pair<int,int>> ppi;
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({grid[0][0],{0,0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[0][0] = 1;
        while (!pq.empty()){
            auto it = pq.top(); pq.pop();
            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;
            int row[] = {0,0,-1,1};
            int col[] = {1,-1,0,0};
            if (r == n-1 and c == m-1) return cost;
            for (int i = 0; i < 4; i++){
                int rnew = r + row[i];
                int cnew = c + col[i];
                if (rnew >= 0 and cnew >= 0 and rnew < n and cnew < n and !visited[rnew][cnew]){
                    visited[rnew][cnew] = 1;
                    pq.push({cost + grid[rnew][cnew], {rnew,cnew}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends