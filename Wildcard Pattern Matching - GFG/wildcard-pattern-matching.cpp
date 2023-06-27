//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = str.size();
        int m = pattern.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,str,pattern,dp);
    }
    
    int f(int i, int j, string str, string pattern,vector<vector<int>> &dp){
        //base case
        if (i < 0 and j < 0) return 1;
        if (i < 0 and j >= 0){
            if (pattern[j] == '*') return f(i,j-1,str,pattern,dp);
            else return 0;
        }
        if (i < 0 or j < 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (pattern[j] == '?' or (str[i] == pattern[j])) return dp[i][j] = f(i-1,j-1,str,pattern,dp);
        else if (pattern[j] == '*') return dp[i][j] = (f(i-1,j,str,pattern,dp) || f(i-1,j-1,str,pattern,dp) || f(i,j-1,str,pattern,dp));
        else return dp[i][j] = 0;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends