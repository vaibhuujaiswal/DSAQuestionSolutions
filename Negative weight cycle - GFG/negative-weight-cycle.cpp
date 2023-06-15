//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int V, vector<vector<int>>edges){
	     vector<int> distance(V,1e8);
        distance[0] = 0;
        for (int i = 0; i < V-1; i++){
            for (int j = 0; j < edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int c = edges[j][2];
                if (distance[u] != 1e8 and distance[u] + c < distance[v]){
                    distance[v] = distance[u] + c;
                }
            }    
        }
        
        for (int j = 0; j < edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int c = edges[j][2];
                if (distance[u] + c < distance[v]){
                    return true;
                }
        }
        
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends