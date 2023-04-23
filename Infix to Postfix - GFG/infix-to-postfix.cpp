//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//   public:
    // Function to convert an infix expression to a postfix expression.
    // string infixToPostfix(string s) {
        // unordered_map<char,int> umap;
        // umap['('] = 0;
        // umap['^'] = 3;
        // umap['*'] = 2;
        // umap['/'] = 2;
        // umap['+'] = 1;
        // umap['-'] = 1;
        // stack<char> stack;
        // string final = "";
        // for (int i = 0; i < s.size();i++){
            // int c = s[i] - '0';
            // if (c >= 'a' - '0' && c <= 'z' - '0'){
                // final += s[i];
            // }else{
            //     if (s[i] == ')'){
            //         while (!stack.empty()){
            //             if (stack.top() == '('){
            //                 stack.pop();
            //                 break;
            //             }else{
            //                 final += stack.top();
            //                 stack.pop();
            //             }
            //         }
            //     }
            //     else if (stack.empty()) {
            //         stack.push(s[i]);
            //         continue;
            //     }else if (umap[s[i]] > umap[stack.top()]){
            //         stack.push(s[i]);
            //         continue;
            //     }else if (umap[s[i]] <= umap[stack.top()] ){
            //         while (!stack.empty() && umap[stack.top()] >= umap[s[i]]){
            //             final += stack.top();
            //             stack.pop();
            //         }
            //         stack.push(umap[s[i]]);
            //     }
            // }
    //     }
    //     while (!stack.empty()){
    //         final += stack.top();
    //         stack.pop();
    //     }
    //     return final;
    // }

class Solution {
  public:
    string infixToPostfix(string s) {
        unordered_map<char,int> umap;
        umap['('] = 0;
        umap['^'] = 3;
        umap['*'] = 2;
        umap['/'] = 2;
        umap['+'] = 1;
        umap['-'] = 1;
        stack<char> stack;
        string final = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push('(');
            } else if (s[i] == ')') {
                while (!stack.empty() && stack.top() != '(') {
                    final += stack.top();
                    stack.pop();
                }
                if (!stack.empty() && stack.top() == '(') {
                    stack.pop();
                }
            } else if (umap.find(s[i]) != umap.end()) {
                while (!stack.empty() && umap[s[i]] <= umap[stack.top()]) {
                    final += stack.top();
                    stack.pop();
                }
                stack.push(s[i]);
            } else {
                final += s[i];
            }
        }
        while (!stack.empty()) {
            final += stack.top();
            stack.pop();
        }
        return final;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends