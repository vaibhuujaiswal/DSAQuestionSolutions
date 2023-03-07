//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_map<int,int> umap;
        for (int i = 0; i < N; i++){
            umap[arr[i]] = i;
        }
        
        int globalCount = 1;
        for (int i = 0; i < N; i++){
            int count = 1;
            if (arr[i] < 0){continue;}
            
            int x = 1;
            while (umap.find(arr[i]+x) != umap.end()){
               arr[umap[arr[i] + x]] = (-1)*arr[umap[arr[i] + x]];
               if (arr[umap[arr[i] + x]] == 0){
                   arr[umap[arr[i] + x]] = -1;
               }
               count++;
               x++;
            }
            
            x = 1;
            while (umap.find(arr[i]-x) != umap.end()){
               arr[umap[arr[i] - x]] = (-1)*arr[umap[arr[i] - x]];
               if (arr[umap[arr[i] - x]] == 0){
                   arr[umap[arr[i] - x]] = -1;
               }
               x++;
               count++;
            }
            globalCount = max(count, globalCount);
        }
        return globalCount;

    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends