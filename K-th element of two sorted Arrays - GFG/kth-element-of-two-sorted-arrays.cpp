//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m){
            return kthElement(arr2, arr1, m, n, k);
        }
        int low = max(0,k-m);
        int high = min(k, n);
        
        while (low <= high){
            int l1;
            int l2;
            int r1;
            int r2;
            int cut1 = (low + high)/ 2;
            int cut2 = k - cut1;
            if (cut1 == 0) l1 = INT_MIN;
            else{
                l1 = arr1[cut1 - 1];
            }
            if (cut2 == 0) l2 = INT_MIN;
            else{
                l2 = arr2[cut2 - 1];
            }
            if (cut1 == n) r1 = INT_MAX;
            else{
                r1 = arr1[cut1];
            }
            if (cut2 == m) r2 = INT_MAX;
            else{
                r2 = arr2[cut2];
            }
            if (l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }
            if (l1 > r2){
                high = cut1 - 1;
            }else{
                low = cut1 + 1;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends