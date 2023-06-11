//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        if (K == 1) return dict[0];
        vector<int> adj[26];
        vector<int> visited(26,-1);
        for (int i = 1; i < N; i++){
            int s1 = 0;
            int s2 = 0;
            bool flag = false;
            while (s1 < dict[i-1].size() and s2 < dict[i].size()){
                if (dict[i-1][s1] != dict[i][s2]){
                    flag = true;
                    adj[dict[i-1][s1] -'0' - 49].push_back(dict[i][s2] - '0' - 49);
                    if (visited[dict[i-1][s1] -'0' - 49] < 0) visited[dict[i-1][s1] -'0' - 49]++;
                    if (visited[dict[i][s2] -'0' - 49] < 0) visited[dict[i][s2] -'0' - 49]++;
                    break;
                }
                s1++;
                s2++;
            }
        }
        stack<int> st;
        for (int i = 0; i < 26; i++){
            if (visited[i] == 0) dfs(i,visited,adj,st);
        }
        string output = "";
        while (!st.empty()){
            output += char(48 + st.top() + 49);
            st.pop();
        }
        return output;
    }
    
    void dfs(int node,vector<int> &visited, vector<int> adj[], stack<int> &st){
        visited[node] = 1;
        for (auto i : adj[node]){
            if (visited[i] == 0) dfs(i,visited,adj,st);
        }
        st.push(node);
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends