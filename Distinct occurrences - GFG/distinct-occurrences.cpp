//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    #define mod 1000000007
    int subsequenceCount(string S, string T)
    {
        int n = S.size(); //i
        int m = T.size(); //j
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (S[i-1] == T[j-1]){
                    curr[j] = (prev[j-1] + prev[j])%mod;
                }else{
                    curr[j] = (prev[j])%mod;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends