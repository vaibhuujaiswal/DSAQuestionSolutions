//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> A;
        unordered_set<string> uset;
        string curr ="";
        if (n == 0) return A;
        if (n == 1){
            A.push_back("()");
            return A;
        }
        para(uset,n,n,n,curr);
        for (auto i : uset){
            A.push_back(i);
        }
        return A;
    }
    
    void para(unordered_set<string> &uset, int n, int openb, int closedb, string curr){
        if (openb == 0 && closedb == 0){
            uset.insert(curr);
            return;
        } 
        if (n == openb){
            openb--;
            para(uset,n,openb,closedb,curr + '(');
            openb++;
        }
        if (closedb > openb){
            closedb--;
            para(uset,n,openb,closedb,curr + ')');
            closedb++;
        }
        if (openb > 0){
            openb--;
            para(uset,n,openb,closedb,curr + '(');
            openb++;
        }
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends