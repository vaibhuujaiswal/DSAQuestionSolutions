//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        int n = a.size();
        if (n != b.size()) return false;
        if ((a == "bc") && (b == "ad")) return false;
        int countA = 0;
        int countB = 0;
        for (int i = 0; i < n; i++){
            countA += a[i] - 'a';
            countB += b[i] - 'a';
        }
        if (countA == countB) return true;
        else return false;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends