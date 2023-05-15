//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> umap(26);
        int uniqueCharacter = 0;
        int r = 0;
        int l = 0;
        int global = -1;
        while (r < s.size()){
            umap[s[r]]++;
            if (umap[s[r]] == 1){
                uniqueCharacter++;
            }
            while (uniqueCharacter > k){
                umap[s[l]]--;
                if (umap[s[l]] == 0) uniqueCharacter--;
                l++;
            }
            if (uniqueCharacter != k){
                r++;
                continue;
            }
            global = max(global,r - l + 1);
            r++;
        }
        return global;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends