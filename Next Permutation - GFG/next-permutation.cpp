//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        int pred = n-1;
        if (n == 1) return arr;
        if (n == 2){
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
            return arr;
        }
        
        //found peak element
        for (int i = n-2; i >= 0; i--){
            if (arr[i] < arr[i+1]){
                pred = i;
                break;
            }
        }
        if (pred == n-1){
            reverse(arr.begin(),arr.begin() + n);
            return arr;
        }
        int suc = INT_MAX;
        for (int i = n-1; i >= 0; i--){
            if (arr[pred] < arr[i]){
                suc = i;
                break;
            }
        }
        
        
        
        int temp = arr[suc];
        arr[suc] = arr[pred];
        arr[pred] = temp;

        reverse(arr.begin()  + pred +  1, arr.end());
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends