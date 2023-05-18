//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num){
        string binary = "";
        vector<string> array;
        choice(num, binary,0,array,-1);
        sort(array.begin(),array.end());
        for (auto i : array){
            cout << i << " ";
        }
    }
    void choice(int num, string binary, int count, vector<string> &array, int previous){
        if (num == count){
            array.push_back(binary);
            return;
        }
        // cout << binary << endl;
        // // cout << (binary[count] - '0');
        // // cout << binary[count];
        if (binary == ""){
            choice(num, binary + "1", count + 1, array,1);
            choice(num, binary + "0", count + 1, array,0);
        }else if (previous == 1){
            choice(num, binary + "0", count + 1, array,0);
            // cout << binary[count];
        }else{
            choice(num, binary + "1", count + 1, array,1);
            choice(num, binary + "0", count + 1, array,0);
        }
}

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends