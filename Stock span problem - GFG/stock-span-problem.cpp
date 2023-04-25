//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> span;
        stack<int> stack;
        for (int i = 0; i < n; i++){
            while (!stack.empty() && price[stack.top()] <= price[i]){
                stack.pop();
            }
            if (stack.empty()){
                span.push_back(i+1); //since stack is empty
                stack.push(i);
            }else{
                span.push_back(i - stack.top());
                stack.push(i);
            }
        }
        return span;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends