//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        if (pre_exp.empty()) return pre_exp;
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string> stack;
        for (int i = 0; i < pre_exp.size(); i++){
            string op;
            op = pre_exp[i];
            if (op != "*" && op != "/" && op != "+" && op != "-"){
                stack.push(op);
            }else{
                string first = stack.top();
                stack.pop();
                string second = stack.top();
                stack.pop();
                string value = first + second + op;
                stack.push(value);
            }
        }
        return stack.top();
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends