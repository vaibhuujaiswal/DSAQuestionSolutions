//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        unordered_map<int,int> umap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        for (int i = 0; i < hand.size(); i++){
            if (umap.find(hand[i]) == umap.end()){
                minheap.push(hand[i]);
            }
            umap[hand[i]]++;
        }
        while (!minheap.empty()){
            vector<int> init;
            for (int i = 0; i < groupSize; i++){
                if (minheap.empty()){
                    return false;
                }
                init.push_back(minheap.top());
                minheap.pop();
            }
            int prev = -1;
            for (int i = 0; i < init.size(); i++){
                if (prev >= 0){
                    if (init[prev] + 1 != init[i]) return false;
                }
                umap[init[i]]--;
                if (umap[init[i]] > 0){
                    minheap.push(init[i]);
                }
                prev = i;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends