//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int counter = 0;
        int temp[r - l + 1]; //temporary array of the size
        int j = m + 1;
        int i = l;
        
        while (i <= m && j <= r){
            if (arr[i] < arr[j]){
                temp[counter] = arr[i];
                counter++;
                i++;
            }else{
                temp[counter] = arr[j];
                counter++;
                j++;}
        }
        
        for (int k = i; k <= m; k++){
            temp[counter] = arr[k];
            counter++;
        }
        
        for (int k = j; k <= r; k++){
            temp[counter] = arr[k];
            counter++;
        }
        counter = 0;
        //transfer temporary array to real array
        for (int k = l; k <= r; k++){
            arr[k] = temp[counter];
            counter++;
        }
        
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r){ //if l == r or less than r than we have reached array of size 1, thus no need to merge anymore
            int mid = l + (r - l)/2; //the divide and conquer is not to create sepe
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends