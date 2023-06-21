//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        for (int i = 0; i < N; i++){
            dp[0][i] = Matrix[0][i];
        }
        
        for (int i = 1; i < N; i++){
            for (int j = 0; j < N; j++){
                int upper = 0;
                int diagonalleft = 0;
                int diagonalright = 0;
                if (j > 0) diagonalleft = Matrix[i][j] + dp[i-1][j-1];
                if (j < N-1) diagonalright = Matrix[i][j] + dp[i-1][j+1];
                upper = Matrix[i][j] + dp[i-1][j];
                dp[i][j] = max(diagonalright,max(upper,diagonalleft));
            }
        }
        
        int finalMax = 0;
        for (int i = 0; i < N; i++){
            finalMax = max(finalMax,dp[N-1][i]);
        }
        return finalMax;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends