//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector <int> arr(m, 0);
        int maxvalue = INT_MIN;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int v = M[i][j];
                if (v == 0){
                    arr[j] = v;
                }
                arr[j] = arr[j] + v;
            }
            maxvalue = maxArea(arr, m, maxvalue);
        }
        return maxvalue;
    }
    
    int maxArea(vector<int> arr, int m, int maxvalue){
        stack<int> stack;
        vector<int> maxleft(m,0);
        vector<int> maxright(m,m-1);
        for (int i = 0; i < m; i++){ //find next smaller element
            while (!stack.empty() && arr[stack.top()] >= arr[i]){
                stack.pop();
            }
            if (!stack.empty()) maxleft[i] = stack.top() + 1;
            stack.push(i);
        }

        while (!stack.empty()) stack.pop();
        for (int i = m-1; i >= 0; i--){
            while (!stack.empty() && arr[stack.top()] >= arr[i]){
                stack.pop();
            }
            if (!stack.empty()) maxright[i] = stack.top() - 1;
            stack.push(i);
        }
        
        for (int i = 0; i < m; i++){
            maxvalue = max(maxvalue, (maxright[i] - maxleft[i] + 1) * arr[i]);
            // cout << maxright[i] << maxleft[i];
        }
        return maxvalue;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends