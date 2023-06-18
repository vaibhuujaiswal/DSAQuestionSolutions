//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> output;
        vector<int> temp;
        combine(0, candidates,target,output,temp);
        return output;
    }
    
    void combine(int ind, vector<int> &candidates, int target, vector<vector<int>> &output, vector<int> temp){
        if (ind == candidates.size() + 1|| target < 0) return;
        if (target == 0){
            output.push_back(temp);
            return;
        }
        for (int i = ind; i  < candidates.size(); i++){
            if (i > ind and candidates[i-1] == candidates[i]) continue;
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            combine(i+1, candidates, target - candidates[i], output, temp);
            temp.pop_back();
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends