//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int target)
    {
        int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n = sizeof(arr)/sizeof(arr[0]);
        vector<int> output;
        if (target == 0) return output;
        for (int i = n-1; i >= 0; i--){
            if (target == 0){
                return output;
            }
            if (arr[i] > target){
                continue;
            }else if (arr[i] == target){
                output.push_back(target);
                return output;
            }else{
                while ((arr[i] <= target) && target > 0){
                    target -= arr[i];
                    output.push_back(arr[i]);
                }
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends