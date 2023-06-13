//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int X, int Y) {
        queue<pair<int,pair<int,int>>> q;
        if (grid[0][0] == 0) return -1;
        q.push({0, {0,0}}); //source distance is zero
        vector<vector<int>> distance(n, vector<int> (m, 1e9));
        distance[0][0] = 0;
        while (!q.empty()){
            auto it = q.front(); q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == X and c == Y){
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends