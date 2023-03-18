//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        unordered_map<char,char> umap;
        int n = str1.length();
        if (n != str2.length()){
            return false;
        }
        int count = 0;
        for (int i = 0; i < n; i++){
            if (umap.find(str1[i]) != umap.end()){
                if (umap[str1[i]] != str2[i]){
                    return false;
                }   
            }else{
                umap[str1[i]] = str2[i];
            }
        }
        umap.clear();

        for (int i = 0; i < n; i++){
            if (umap.find(str2[i]) != umap.end()){
                if (umap[str2[i]] != str1[i]){
                    return false;
                }   
            }else{
                umap[str2[i]] = str1[i];
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends