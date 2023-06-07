//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
	    vector<vector<int>> output = visited;
	    queue<pair<pair<int,int>,int>> q;
	    //multisourcing for bfs queue;
	    for (int i= 0; i < grid.size(); i++){
	        for (int j = 0; j < grid[i].size() ; j++){
	            if (grid[i][j] == 1){
	                q.push({{i,j},0});
	            }
	        }
	    }
	   while (!q.empty()){
	       auto it = q.front(); q.pop();
	       int r = it.first.first;
	       int c = it.first.second;
	       int distance = it.second;
	       if (visited[r][c]) continue;
	       visited[r][c] = 1;
	       output[r][c] = distance;
	       int rvar[] = {1,0,0,-1};
	       int cvar[] = {0,1,-1,0};
	       for (int i = 0; i < 4; i++){
	           if (r + rvar[i] >= 0 and c + cvar[i] >= 0 and 
	           r + rvar[i] < grid.size() and c + cvar[i] < grid[0].size() and
	           !visited[r + rvar[i]][c + cvar[i]]){
	               q.push({{r + rvar[i],c + cvar[i]},distance+1});
	           }
	       }
	   }
	   return output;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends