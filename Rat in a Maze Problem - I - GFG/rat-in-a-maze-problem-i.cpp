//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited(n,vector<int>(n,0));
        vector<string> output;
        string s = "";
        if (m[0][0] == 0) return output;
        visited[0][0] = 1;
        ratmaze(s,0,0,output,m,n, visited);
        return output;
    }
    
    void ratmaze(string s, int r, int c, vector<string> &output, vector<vector<int>> &m , int n,vector<vector<int>> visited){
        if (r < 0 and c < 0 and r >= n and c >= n) return;
        if (r == n-1 and c == n-1 and m[n-1][n-1] == 1){
            output.push_back(s);
            return;
        }
        int row[] ={0,0,-1,1};
        int col[] = {-1,1,0,0};
        string letter[] = {"L","R","U","D"};
        
        for (int i = 0; i < 4; i++){
            int rnew = r + row[i];
            int cnew = c + col[i];
            if (rnew >= 0 and cnew >= 0 and rnew < n and cnew < n and !visited[rnew][cnew]){
                if (m[rnew][cnew]){
                    visited[rnew][cnew] = 1;
                    s += letter[i];
                    ratmaze(s,rnew,cnew,output,m,n,visited);
                    s.pop_back();
                    visited[rnew][cnew] = 0;
                }
            }
        }
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends