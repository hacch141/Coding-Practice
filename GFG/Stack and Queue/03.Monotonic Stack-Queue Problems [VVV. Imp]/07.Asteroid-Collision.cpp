// Asteroid Collision


// Leetcode
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(auto i : asteroids) {
            // if top is -ve then we can push any directions asteroid
            if(st.empty() || i>0 || st.top()<0) {
                st.push(i);
            }
            else {
                while(!st.empty() && st.top()>0 && abs(i)>st.top()) {
                    st.pop();
                }
                if(st.empty() || st.top()<0) {
                    st.push(i);
                }
                else if(!st.empty() && abs(i)==st.top()) {
                    st.pop();
                }
            }
        }

        int len = st.size();
        vector<int> ans(len);

        for(int i=0; i<len; i++) {
            ans[len-1-i] = st.top();
            st.pop();
        }

        return ans;
    }
};
// T : O(N)
// S : O(N)



// Code Studio
#include <bits/stdc++.h>

vector<int> collidingAsteroids(vector<int> &asteroids)
{
    //    Write your code here.
    stack<int> st;

    for(auto i : asteroids) {
        // if top is -ve then we can push any directions asteroid
        if(st.empty() || i>0 || st.top()<0) {
            st.push(i);
        }
        else {
            while(!st.empty() && st.top()>0 && abs(i)>st.top()) {
                st.pop();
            }
            // main change is =0 here
            if(st.empty() || st.top()<=0) {
                st.push(i);
            }
            else if(!st.empty() && abs(i) == st.top()) {
                st.pop();
            }
        }
    }

    vector<int> ans(st.size());
    for (int i=st.size()-1; i>=0; i--) {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}
// T : O(N)
// S : O(N)
