//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<int> s;
        for (int i = 0; i < x.size() ; i++){
            if (x[i] - '0' == '{' - '0' || x[i] - '0'== '[' - '0' || x[i] - '0'== '(' -'0')
            {   
                s.push(x[i] - '0');
                continue;
            }
            if (s.empty()){
                return false;
            }
            if (x[i] - '0' == '}'- '0' && s.top() == '{'- '0') s.pop();
            else if (x[i] - '0' == ')'- '0' && s.top() == '('- '0') s.pop();
            else if (x[i] - '0' == ']'- '0' && s.top() == '['- '0') s.pop();
            else{
                return false;
            }
        }
        return s.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends