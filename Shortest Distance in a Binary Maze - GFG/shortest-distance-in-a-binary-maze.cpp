//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {source.first,source.second}}); //source distance is zero
        vector<vector<int>> distance(n, vector<int> (m, 1e9));
        distance[source.first][source.second] = 0;
        while (!q.empty()){
            auto it = q.front(); q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == destination.first and c == destination.second){
                return dist;
            }
            int row[4] = {0,0,-1,1};
            int col[4] = {1,-1,0,0};

            for (int i = 0; i < 4; i++){
                int rnew = r + row[i];
                int cnew = c + col[i];
                
                if (rnew >= 0 and rnew < n and cnew >= 0 and cnew < m){
                    if (distance[rnew][cnew] == 1e9 and grid[rnew][cnew]){
                        distance[rnew][cnew] = dist + 1;
                        q.push({distance[rnew][cnew],{rnew,cnew}});
                    }
            }
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends