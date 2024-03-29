//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
// public:
// 	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
// 	    // Code here
// 	}
// };

class Solution
{
  public:
    bool isPossible(int n, vector<pair<int, int> >& prerequisites) 
    {
        int m = prerequisites.size();
        vector<int> adj[n];
        for (int i = 0; i < m; i++){
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> indegree(n,0);
        for (int i = 0; i < n; i++){
            for (auto k : adj[i]){
                indegree[k]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }
        int topo = 0;
        while (!q.empty()){
            int node =  q.front(); q.pop();
            topo++;
            for(auto it : adj[node]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if (topo == n) return true;
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends