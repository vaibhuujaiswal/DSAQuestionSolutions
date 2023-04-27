//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_map<char,int> umap; //should have used set
	    string final = "";
	    for (int i = 0; i < str.size(); i++){
	        if (umap.find(str[i]) == umap.end()){
	            umap[str[i]] = 1;
	            final += str[i];
	        }else{
	            umap[str[i]]++;
	        }
	    }
	    return final;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends