//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n, 0));
        int r = 0;
        int c = 0;
        int x = 0;
        int y = 0;
        for (r = 0; r < n ; r++){
            for (c = 0; c < n; c++){
                if (grid[r][c] == 1){
                    x = r;
                    y = c;
                    break;
                }
            }
        }
        visited[x][y] = 1;
        return dfs(x,y,grid,visited);
    }
    
    bool dfs(int r, int c, vector<vector<int>> grid, vector<vector<int>> &visited){
        int n = grid.size();
        int rvalue[] = {0,-1,1,0};
        int cvalue[] = {-1,0,0,1};
        for (int i = 0; i < 4; i++){
            int newr = r + rvalue[i];
            int newc = c + cvalue[i];
            if (newr < n and newc < n and newr >= 0 and newc >= 0){
                if (!visited[newr][newc]){
                    visited[newr][newc] = 1;
                    if (grid[newr][newc] == 0) continue; //wall
                    if (grid[newr][newc] == 2) return true; //reached end
                    if (dfs(newr,newc,grid,visited) == true) return true;
                }
            }
        }
        return false;
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
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends