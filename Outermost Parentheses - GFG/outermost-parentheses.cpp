//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        stack<int> stack;
        if (s == "" || s == "()") return "";
        string finalString = "";
        int flag = 0;
        for (int i = 0; i < s.size(); i++){
            if (stack.empty()){
                stack.push(s[i] - '0');
                continue;
            }
            if (!stack.empty() && s[i] - '0' == ('(' - '0')){
                finalString += s[i];
                flag++;
                continue;
            }
            if (flag != 0 && s[i] - '0' == ')' - '0'){
                finalString += s[i];
                flag--;
                continue;
            }
            if (flag == 0 && !stack.empty() && s[i] - '0' == ')'- '0'){
                stack.pop();
            }
        }
        return finalString;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends