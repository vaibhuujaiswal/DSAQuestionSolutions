//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        vector<int> output;
        if (n == 1) {
            output.push_back(A[0] + B[0]);
            return output;
        }
        priority_queue<pair<int,pair<int,int>>> maxheap; //to check for maxheap;
        set<pair<int,int>> s; //to check for duplicates
        maxheap.push({A[0] + B[0],{0,0}});
        s.insert({0,0});
        while (k > 0){
            auto i = maxheap.top(); maxheap.pop();
            output.push_back(i.first);
            int L = i.second.first;
            int R = i.second.second;
            if (k > 0 && L < n-1 && R < n-1 && s.find({L+1,R}) == s.end()){
                maxheap.push({A[L+1] + B[R],{L+1,R}});    
                s.insert({L+1,R});
            }
            if (k > 0 && L < n-1 && R < n-1 && s.find({L,R+1}) == s.end()){
                maxheap.push({A[L] + B[R+1],{L,R+1}}); 
                s.insert({L,R+1});
            }
            k--;
        }
        
        return output;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends