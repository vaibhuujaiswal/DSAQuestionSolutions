//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        int i = 0;
        int j = 0;
        int type1 = -1;
        int type2 = -1;
        int counttype1 = 0;
        int counttype2 = 0;
        int count = 0;
        while (i < N){
            if (type1 == -1) {
                type1 = fruits[i];
                counttype1++;
            }else if (fruits[i] == type1){
                counttype1++;
            }else if (type2 == -1){
                type2 = fruits[i];
                counttype2++;
            }else if (fruits[i] == type2){
                counttype2++;
            }else{
                while ((counttype1 != 0 && counttype2 != 0) && j < i){
                    if (fruits[j] == type1){
                        counttype1--;
                    }else{
                        counttype2--;
                    }
                    j++;
                }
                if (counttype1 == 0){
                    type1 = fruits[i];
                    counttype1++;
                }else{
                    type2 = fruits[i];
                    counttype2++;
                }
            }
            count = max(count, i - j + 1);
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends