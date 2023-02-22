//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        auto Nby2 = (size + 1)/2;
        int vote = 1;
        int element = a[0];
        for (int i = 1; i < size; i++){
            if (vote == 0){
                element = a[i];
            }
            if (a[i] == element){
                vote++;
            }else{
                vote--;
            }
        }
        
        auto count = 0;
        if (vote == 0){
            return -1;    
        }else{
            for (int i = 0; i < size; i++){
                if (element == a[i]){
                    count++;
                }
            }
            if (count >= Nby2){
                return element;
            }else{
                return -1;
            }
        }
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends