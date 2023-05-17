//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int fiveDollar = 0;
        int tenDollar = 0;
        int twentyDollar = 0;
        for (int i = 0; i < N; i++){
            if (bills[i] == 5){
                fiveDollar++; 
            }else if (bills[i] == 10){
                tenDollar++;
                fiveDollar--;
            }else if (bills[i] == 20){
                twentyDollar++;
                if (tenDollar == 0){
                    fiveDollar -= 3;
                }else{
                    tenDollar--;
                    fiveDollar--;
                }
            }
            
            if (fiveDollar < 0 || tenDollar < 0 || twentyDollar< 0){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends