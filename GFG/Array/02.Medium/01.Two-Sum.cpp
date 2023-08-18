// Two Sum

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    unordered_map<int,int> mp;
    for(auto i : book) {
        int rem = target - i;
        if(mp.find(rem) != mp.end()) {
            return "YES";
        }
        mp[i]++;
    }
    return "NO";
}
// T : O(N)
// S : O(N)

string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(),book.end());
    int left = 0;
    int right = n-1;
    while(left < right) {
        if(book[left] + book[right] == target) {
            return "YES";
        }
        else if(book[left] + book[right] < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return "NO";
}
// T : O(N * Log N)
// S : O(N)


