//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        sort(A,A + N);
        int finalSum = 1000000000;
        for (int i = 0; i < N; i++){
            int l = i+1;
            int r = N-1;
            while (l < r){
                int sum = A[i] + A[l] + A[r];
                if (sum == X) return sum;
                if (abs(X - sum) < abs(X - finalSum)) {
                    finalSum = sum;
                }
                if (sum < X) l++;
                else r--;
            }
        }
        return finalSum;
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
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends