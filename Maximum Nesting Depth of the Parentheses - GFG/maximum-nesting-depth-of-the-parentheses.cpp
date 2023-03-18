//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        stack<int> stack;
        int depth = 0;
        int maxdepth = 0;
        for (int i = 0; i < s.size();i++){
            if (s[i] -'0' == '(' - '0'){
                stack.push(s[i]);
                depth++;
                maxdepth = max(depth,maxdepth);
            }else if (s[i] -'0' == ')' - '0'){
                if (!stack.empty()){
                    stack.pop();
                    depth--;
                }
            }
        }
        return maxdepth;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends