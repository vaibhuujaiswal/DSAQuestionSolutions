//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int count = 0;
        int maxfreq = 0;
        unordered_map<char,int> umap(26);
        while (r < s.size()){
            umap[s[r]]++;
            maxfreq = max(maxfreq,umap[s[r]]);
            while ((r - l + 1 - maxfreq) > k){
                umap[s[l]]--;
                l++;
            }
            count = max(count, r - l + 1);
            r++;
        }
        return count;
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
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends