// Remove k Digits

string removeKDigits(string num, int k) 
{
    // Write your code here.
    if(num == "0") return "0";

    stack<char> st;

    for(auto i : num) {
        // if prev digit is greater than curr then pop it out
        while(!st.empty() && k>0 && i<st.top()) {
            st.pop();
            k--;
        }

        // if stack is empty no need to add leading zero just ignore it
        if(st.empty() && i=='0') {
            continue;
        }

        // otherwise push the digit
        st.push(i);
    }

    // if we make smallset string but the k is remaining
    while(!st.empty() && k) {
        st.pop();
        k--;
    }

    // if all digits are popped and get empty string
    if(st.empty()) return "0";

    int n = st.size();
    string ans(n,' ');
    for(int i=0; i<n; i++) {
        ans[n-1-i] = st.top();
        st.pop();
    }

    return ans;
}
// T : O(N)
// S : O(N)
