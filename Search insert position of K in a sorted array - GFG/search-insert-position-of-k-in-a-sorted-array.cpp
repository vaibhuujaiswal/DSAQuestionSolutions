//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        int ind = -1;
        int dist = INT_MAX;
        int l = 0; int r = N-1;
        while (l <= r){
            int m = l + (r - l)/2;
            if (Arr[m] == k) return m;
            if (abs(Arr[m] - k) <= dist){
                dist = abs(Arr[m] - k);
                ind = m;
            }
            if (l == r){
                break;
            }
            if (Arr[m] < k) l = m+1;
            else r = m-1;
        }
        if (Arr[ind] > k) return ind;
        else return ind+1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends