//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(visited, grid, i, j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int r, int c) {
        visited[r][c] = true;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (r + dr >= 0 && c + dc >= 0 && r + dr < grid.size() && c + dc < grid[0].size()) {
                    if (!visited[r + dr][c + dc] && grid[r + dr][c + dc] == '1') {
                        dfs(visited, grid, r + dr, c + dc);
                    }
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends