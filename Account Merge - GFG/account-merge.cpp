//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            size.resize(n,1);
            parent.resize(n);
            for (int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if (node == parent[node]){
                return node;
            }else{
                return parent[node] = findParent(parent[node]);
            }
        }
        
        void findUnionBySize(int node1, int node2){
            int u = findParent(node1);
            int v = findParent(node2);
            if (u == v) return;
            if (size[u] > size[v]){
                size[u] += size[v];
                parent[v] = u;
            }else{
                size[v] += size[u];
                parent[u] = v;
            }
        }
};


class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string,int> umap;
        for (int i = 0; i < n; i++){
            for (int j = 1; j < details[i].size(); j++){
                string value = details[i][j];
                if (umap.find(value) == umap.end()) {
                    umap[value] = i;
                } else {
                ds.findUnionBySize(i, umap[value]);
                }

            }
        }
        
        vector<string> mergedMail[n];
        for (auto it : umap){
            string stringv = it.first;
            int numberTag = it.second;
            int node = ds.findParent(numberTag);
            mergedMail[node].push_back(stringv);
        }
        
        vector<vector<string>> ans;
        for (int i = 0; i < n ; i++){
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> arr;
            arr.push_back(details[i][0]);
            for (auto iterator : mergedMail[i]){
                arr.push_back(iterator);
            }
            ans.push_back(arr);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends