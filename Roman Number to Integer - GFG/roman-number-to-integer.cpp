//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char,int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;

        int n = str.length();
         int count = 0;
        if (n == 1){
            count = umap[str[0]];
            return count;
        }
        char previous = str[n - 1];
    
        count += umap[previous];
        for (int i = n - 2; i >= 0; i--){
            if (umap[previous] > umap[str[i]]){
                 count -= umap[str[i]];
                 continue;
            }
            count += umap[str[i]];
            previous = str[i];
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends