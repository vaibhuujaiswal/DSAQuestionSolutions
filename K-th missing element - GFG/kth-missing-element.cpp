//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int arr[], int n, int k)
{
    int i = 0;
    int count = arr[0];
    while (i < n){
        if (arr[i] == count){
            i++;
            count++;
        }else{
            count++;
            k--;
        }
        if (k == 0) return count-1;
    }
    
    return -1;
}