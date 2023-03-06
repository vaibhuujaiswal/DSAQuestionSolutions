//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> result;
    int l = 0;
    int r = n-1;
    //leftmost pair
    
    while (l <= r){
        int m = l + (r-l)/2;
        if (arr[m] == x){
            if (m - 1 >= 0){
                if (arr[m-1] != arr[m]) {
                    result.push_back(m);
                    break;
                }
            }
            if (m == 0){
                result.push_back(m);
                break;
            }
            
            else{
                r = m - 1;
                continue;
            }
        }
        if (arr[m] < x) l = m+1;
        else r = m-1;
    }
    
    l = 0;
    r = n-1;
    //rightmost pair
    while (l <= r){
        int m = l + (r - l)/2;
        if (arr[m] == x){
            if (m + 1 < n){
                if (arr[m+1] != arr[m]){
                    result.push_back(m);
                    break;
                }
            }
            if (m == n-1){
                result.push_back(m);
                break;
            }else{
                l = m + 1;
                continue;
            }
        }
        
        if (arr[m] < x) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    
    if (result.size() == 0){
        result.push_back(-1);
        result.push_back(-1);
    }
    
    return result;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends