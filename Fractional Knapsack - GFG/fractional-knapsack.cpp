//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution {
public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        vector<pair<double, int>> frac;
        for (int i = 0; i < n; i++) {
            double weig = arr[i].weight;
            double val = arr[i].value;
            frac.push_back(make_pair(val / weig, i));
        }
        sort(frac.rbegin(), frac.rend()); // Sort in descending order

        int l = 0;
        double sum = 0;
        while (l < frac.size() && W > 0) {
            if (arr[frac[l].second].weight > W) {
                sum += W * frac[l].first;
                W = 0;
            } else {
                sum += arr[frac[l].second].value;
                W -= arr[frac[l].second].weight;
            }
            l++;
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends