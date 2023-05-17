//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool mycomp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
        if (a.first.second < b.first.second){
            return true;
        }else if (a.first.second > b.first.second){
            return false;
        }else{
            if (a.first.first < b.first.first){
                return true;
            }else if (a.first.first > b.first.first){
                return false;
            }else if (a.second < b.second){
                return true;
            }else{
                return false;
            }
        }
        return true;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<pair<int,int>,int>> value;
        for (int i = 0; i < n; i++){
            pair<int,int> temp = make_pair(start[i],end[i]);
            pair<pair<int,int>,int> temp1 = make_pair(temp,i);
            value.push_back(temp1);
        }
        sort(value.begin(),value.end(),mycomp);
        
        // for (auto i : value){
        //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        // }
        
        int endlimit = 0;
        int count = 0;
        for (int i = 0; i < n; i++){
            if ((value[i].first.first <= endlimit)){
                continue;
            }
            if (value[i].first.second > endlimit){
                endlimit = value[i].first.second;
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends