//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        vector<int> final;
        stack<int> stack;
        bool collided = false;
        for (int i = n-1; i >= 0; i--){
            if (!stack.empty()){
                while (!stack.empty() && (abs(stack.top()) != stack.top()) && (asteroids[i] == abs(asteroids[i]))){
                    if (abs(asteroids[i]) == abs(stack.top())) {
                        stack.pop();
                        collided = true;
                        break;
                    }
                    else if (abs(asteroids[i]) > abs(stack.top())){
                        stack.pop();
                    }else{
                        collided = true;
                        break;
                    }
                }
                if (!stack.empty() && abs(stack.top()) == stack.top() && asteroids[i] != abs(asteroids[i])){
                    stack.push(asteroids[i]);
                    continue;
                }
            }
            if (!collided){
                stack.push(asteroids[i]);
            }
            collided = false;
        }
        while (!stack.empty()){
            final.push_back(stack.top());
            stack.pop();
        }
        return final;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends