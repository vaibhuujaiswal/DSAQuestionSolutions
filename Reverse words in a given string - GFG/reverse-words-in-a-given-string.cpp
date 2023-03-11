//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        int n = S.size();
        if (n == 1) return S;
        int l = 0;
        int r = n - 1;
        while (l < r){
            char temp = S[l];
            S[l] = S[r];
            S[r] = temp;
            r--;
            l++;
        }
        
        
        l = 0;
        for (int i = 0; i < n; i++){
            if (S[i] == '.' || S[i] == '\0'){
                int left = l;
                int right = i - 1;
                while (left < right){
                    char temp = S[left];
                    S[left] = S[right];
                    S[right] = temp;
                    right--;
                    left++;
                }
                l = i+1;
            }
        }
        

        int left = l;
        int right = n-1;
        while (left < right){
            char temp = S[left];
            S[left] = S[right];
            S[right] = temp;
            right--;
            left++;
        }
        return S;  
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends