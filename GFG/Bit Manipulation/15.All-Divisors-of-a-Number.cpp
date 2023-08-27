// All Divisors of a Number

vector<int> printDivisors(int n) {
    // Write your code here
    vector<int> ans;
    for(int i=1; i*i<=n; i++) {
        if(n%i == 0) {
            ans.push_back({i});
            if(n/i != i) {
                ans.push_back({n/i});
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
// T : O(sqrt(N))
// S : O(1)


/*
    Time Complexity: O(N).
    Space Complexity: O(1).

    where 'N' is the given number.
*/

vector<int> printDivisors(int n)
{
    vector<int> ans;

    // Traversing from 1 to 'N'.
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
