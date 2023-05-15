//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // 1-p(failure) //which means we have to calculate the 
        //number of times we do not get a count
        // Code here
        int r = 0;
        int l = 0;
        int count = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while (r < s.size()){
            if (s[r] == 'a'){
                a++;
            }else if (s[r] == 'b'){
                b++;
            }else if (s[r] == 'c'){
                c++;
            }
            
            while (a  > 0 && b > 0 && c > 0){

                if (s[l] == 'a'){
                    a--;
                }else if (s[l] == 'b'){
                    b--;
                }else if (s[l] == 'c'){
                    c--;
                }

                l++;
            }
            
            
            count += r - l + 1;
            r++;
        }
        int sum = 0;
        for (int i = 0; i < s.size(); i++){
            sum += (i+1);
        }
        // cout << sum;
        // cout << count;
        return sum - count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends