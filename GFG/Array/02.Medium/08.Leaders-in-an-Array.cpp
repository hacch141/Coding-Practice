// Leaders in an Array

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i=n-1; i>=0; i--) {
        if(a[i] > maxi) {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }

    return ans;
}
// T : O(N)
// S : O(1)



vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}
// T : O(N^2)
// S : O(1)
