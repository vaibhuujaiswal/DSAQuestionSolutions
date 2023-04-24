//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    public:
    int prec(string s){
        if (s == "*" || s == "/"){
            return 2;
        }else if (s == "+" || s == "-"){
            return 1;
        }else return 0;
    }
    
  public:
    string preToInfix(string pre_exp) {
        if (pre_exp.empty()) return pre_exp;
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string> stack;
        for (int i = 0; i < pre_exp.size(); i++){
            string op;
            op = pre_exp[i];
            if (!prec(op)){
                stack.push(op);
            }else{
                string first = stack.top();
                stack.pop();
                string second = stack.top();
                stack.pop();
                string final = "(" +first + op + second + ")";
                stack.push(final);
            }
        }
        string ret;
        while (!stack.empty()){
            ret += stack.top();
            stack.pop();
            return ret;
        }
        return ret;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends