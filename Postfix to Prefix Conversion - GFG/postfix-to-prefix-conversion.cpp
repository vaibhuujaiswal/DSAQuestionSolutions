//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> stack;
        for (int i = 0; i < post_exp.size(); i++){
            string op;
            op = post_exp[i];
            if (op != "*" && op != "/" && op != "+" && op != "-"){
                stack.push(op);
            }else{
                string first = stack.top();
                stack.pop();
                string second = stack.top();
                stack.pop();
                stack.push(op + second + first); // order based on conversion to postfix
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
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends