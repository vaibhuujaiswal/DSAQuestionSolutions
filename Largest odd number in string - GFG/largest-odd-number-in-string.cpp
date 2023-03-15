//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        bool flag = false;
        string k = "";
        for (int i = s.size() - 1; i >= 0; i--){
            int value = s[i] - '0';
            if (!flag){
                if (checkOdd(value)){
                    k += s[i];
                    flag = true;
                    continue;
                }else continue;
            }
            
            if (flag) {
                k += s[i];
            }
            
        }
        int n = k.size();
        k = reverse(k, n);
        return k;
    }
    
    public:
        bool checkOdd(int i){
            if (i % 2 != 0){
                return true;
            }
            return false;
        }
        
    public:
        string reverse(string k, int n){
            if (n == 1) return k;
            int l = 0;
            int r = n-1;
            while (l < r){
                char temp;
                temp = k[l];
                k[l] = k[r];
                k[r] = temp;
                l++;
                r--;
            }
            return k;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends