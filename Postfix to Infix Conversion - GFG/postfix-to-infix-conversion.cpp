//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> stack;
        for (int i = 0; i < exp.size(); i++){
            string op;
            op = exp[i];
            if (op != "+" && op != "-" && op != "/" && op != "*" && op != "^"){
                stack.push(op);
            }else{
                string first = stack.top();
                stack.pop();
                string second = stack.top();
                stack.pop();
                stack.push("(" + second + op + first + ")");
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends