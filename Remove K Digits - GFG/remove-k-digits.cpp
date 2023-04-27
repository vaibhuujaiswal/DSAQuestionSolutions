//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        if (K == 0) return S;
        stack<int> stack;
        string final = "";
        if (K == S.size()) return final;
        bool flag = false;
        for (int i = 0; i < S.size(); i++){
            while (!stack.empty() && stack.top() > (S[i] - '0') && K > 0){
                stack.pop();
                K--;
            }
            if (S[i] == '0' && stack.empty()) {
                flag = true;
                continue;
            }
            stack.push(S[i] - '0');
        }
        while (K > 0 && !stack.empty()){
            stack.pop();
            K--;
        }
        while (!stack.empty()){
            final = to_string(stack.top()) + final;
            stack.pop();
        }
        if (final.size() == 0 && flag) final = "0";
        return final;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends