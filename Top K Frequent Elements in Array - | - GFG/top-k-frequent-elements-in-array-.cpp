//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

    typedef pair<int,int> ppi;

class myComp{
    public:
        bool operator()(ppi a, ppi b){
            if (a.first > b.first) return true;
            else if (a.first < b.first) return false;
            else if (a.second > b.second) return true;
            else return false;
        }
};

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        typedef pair<int,int> ppi;

        vector<int> output;
        unordered_map<int,int> umap;
        for (int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        priority_queue<ppi, vector<ppi>, myComp> pq;
        for (auto j : umap){
            pq.push({j.second, j.first});
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()){
            output.push_back(pq.top().second);
            pq.pop();
        }
        reverse(output.begin(),output.end());
        return output;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends