//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if (s.size() == 0 || p.size() == 0 || s.size() < p.size()) return "-1";
        
        int umap[256] = { 0 };
        int freqCount = 0;
        for (int i = 0; i < p.length(); i++) {
            if (umap[p[i]] == 0)
                freqCount++;
            umap[p[i]]++;
        }
        
        int l = 0;
        int r = 0;
        int minimum = INT_MAX;
        int minl = 0;
        
        while (r < s.length()){
            umap[s[r]]--;
            if (umap[s[r]] == 0){
                freqCount--;
            }
            
            if (freqCount == 0){
                while (freqCount == 0){
                    if (umap[s[l]] == 0) freqCount++;
                    if ((r - l + 1) < minimum){
                        minimum = min(minimum,r - l + 1);
                        minl = l;
                    }
                    umap[s[l]]++;
                    // if (umap[s[l]] > 0) freqCount++;
                    l++;
                }
            }
            r++;
        }
        
        if (minimum == INT_MAX){
            return "-1";
        }
        return s.substr(minl, minimum);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends