//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int count = 0;
        int n = str.length();
        int v = 0;
        bool flag = false;
        if (str[0] == '-'){
            flag = true;
            if (n == 1) return -1;
            v++;
        }
        for (int i = v; i < n; i++){
            int value = str[i] - '0';
            // cout << i << " " << value;
            if (value >= 0 && value <= 9){
                // cout << "The value of cout :" << count << " ";
                count = (count * 10) + value;
            }else{
                return -1;
            }
        }
        if (flag == true){
            count = count * (-1); 
            return count;
        }else{
            return count;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends