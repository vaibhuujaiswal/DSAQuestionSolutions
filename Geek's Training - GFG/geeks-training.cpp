//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(n-1,3,points,n,dp);
    }
    
    int f(int day, int task,vector<vector<int>>& points, int n, vector<vector<int>> &dp){
        //base case to be established
        if (day == 0){
            int maxbasecase = 0;
            for (int i = 0 ; i < 3; i++){
                if (i != task){
                    maxbasecase = max(maxbasecase,points[day][i]);
                }
            }
            return dp[day][task] = maxbasecase;
        }
        if (dp[day][task] != -1) return dp[day][task];
        
        int maxi = 0;
        for (int i = 0; i < 3; i++){
            if (i != task){
                int point = points[day][i] + f(day-1,i,points,n,dp);
                maxi = max(maxi,point);
            }
        }
        return dp[day][task] = maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends