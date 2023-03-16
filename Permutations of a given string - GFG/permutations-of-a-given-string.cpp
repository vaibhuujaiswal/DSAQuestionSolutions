//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> store;
		    if (S.size() == 1){
		        store.push_back(S);
		        return store;
		    }else if (S.size() == 2){
		        store.push_back(S);
		        string temp;
		        temp += S[1];
		        temp += S[0];
		        store.push_back(temp);
		        return store;
		    }
		    string curr = "";
		    int n = S.size();
		    p(S,store,curr,n);
		    sort(store.begin(),store.end());
		    vector<string> final;
		    final.push_back(store[0]);
		    for (int i = 1; i < store.size(); i++){
		        if (final.back() != store[i]){
		            final.push_back(store[i]);
		        }
		    }
		    
		    return final;
		}
		
	public:
	    void p(string S,vector<string>& store,string curr, int n){
	        for (int i = 0; i < S.size(); i++){
	            string temp = "";
	            temp += curr;
	            temp += S[i];
	            string news = "";
	            if (i-1 >= 0) news += S.substr(0,i);
	            if (i+1 < S.size()) news += S.substr(i+1);
	            p(news,store,temp,n);
	        }
	        if (curr.size() == n) store.push_back(curr);
	    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends