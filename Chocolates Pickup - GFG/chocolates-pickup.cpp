//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<int>> front(m,vector<int>(m,0));
        
        for (int j1 = 0; j1 < m; j1++){
            for (int j2 = 0; j2 < m; j2++){
                if (j1 == j2) front[j1][j2] = grid[n-1][j2];
                else front[j1][j2] = grid[n-1][j2] + grid[n-1][j1];
            }
        }
        vector<vector<int>> curr(m,vector<int>(m,0));
        for (int i = n-2; i >= 0; i--){
            for (int j1 = 0; j1 < m; j1++){
                for (int j2 = 0; j2 < m; j2++){
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= +1; dj1++){
                        for (int dj2 = -1; dj2 <= +1; dj2++){
                            int value = 0;
                            int j1new = j1 + dj1;
                            int j2new = j2 + dj2;
                            if (j1 == j2) value += grid[i][j2];
                            else value = grid[i][j1] + grid[i][j2];
                            
                            if (j1new >= 0 and j2new >= 0 and j1new < m and j2new < m){
                                value += front[j1new][j2new];
                            }else{
                                value -1e9;
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends