//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for (int j = 0; j < n; j++){
            for (int i = 0; i < n; i++){
                if (M[j][i] == 1){
                    s.push(i);
                }
            }
            if (!s.empty()) break;
        }
        while (!s.empty()){
            int c = s.top();
            s.pop();
            bool flag = true;
            for (int i = 0; i < n; i++){
                if (M[c][i] == 1){
                    flag = false;
                    break;
                }
            }
            bool check = true;
            if (flag){
                for (int i = 0; i < n; i++){
                    if (M[i][c] == 0 && i != c){
                        check = false;
                        break;
                    }
                }
                if (check) return c;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends