//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2) q.push(make_pair(i,j));
            }
        }
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()){
            count++;
            int size = q.size();
            for (int k = 0; k < size; k++){
                auto pair  = q.front(); q.pop();
                int i = pair.first;
                int j = pair.second;
                if (i-1 >= 0){
                    if (grid[i-1][j] == 1){
                        grid[i-1][j] = 2;
                        q.push(make_pair(i-1,j));
                    }
                }
                if (i+1 < n){
                    if (grid[i+1][j] == 1){
                        grid[i+1][j] = 2;
                        q.push(make_pair(i+1,j));
                    }
                }
                if (j-1 >= 0){
                    if (grid[i][j-1] == 1){
                        grid[i][j-1] = 2;
                        q.push(make_pair(i,j-1));
                    }
                }
                if (j+1 < m){
                    if (grid[i][j+1] == 1){
                        grid[i][j+1] = 2;
                        q.push(make_pair(i,j+1));
                    }
                }
            }
        }
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {
                    return -1; 
                }
            }
        }
        return count-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends