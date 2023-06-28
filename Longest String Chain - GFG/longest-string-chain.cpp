//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(),words.end(), mycomp);
        // for (auto i : words){
        //     cout << i << " ";
        // }
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int output = f(0,-1,words,dp,n);
        if (output == 0) return 1;
        else return output;
    }
    
    bool static mycomp(string a, string b){
        return (a.size() < b.size());
    }
    
    int f(int ind, int prev_ind,vector<string>& words, vector<vector<int>> &dp, int n){
        if (ind == n) return 0;
        if (dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int nottake = f(ind+1,prev_ind,words,dp,n);
        int take = 0;
        if (checkSubsequence(ind,prev_ind,words)){
            take = 1 + f(ind+1,ind,words,dp,n);
        }
        return dp[ind][prev_ind+1] = max(take,nottake);
    }
    
    bool checkSubsequence(int ind, int prev_ind, vector<string>& arr){
        if (prev_ind == -1) return true;
        if (arr[ind].size() <= arr[prev_ind].size()) return false;
        int i = 0; int j = 0;
        string succ = arr[ind];
        string pred = arr[prev_ind];
        int n = pred.size();

        if (succ.size() != n+1) return false;
        bool allowedOnce = true;
        while (i < n){
            if (pred[i] == succ[j]){
                i++;
                j++;
            }else{
                if (allowedOnce){
                    j++;
                    allowedOnce = false;
                }else{
                    return allowedOnce;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends