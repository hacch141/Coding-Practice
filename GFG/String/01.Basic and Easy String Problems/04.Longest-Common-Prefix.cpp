// Longest Common Prefix

string commonPrefix(vector<string>& arr,int n){
	//Write your code here
  	sort(arr.begin(),arr.end());
  	int n1 = arr[0].length();
  	int n2 = arr[n-1].length();
  	int start = 0;
  	
  	while(start < min(n1,n2) && arr[0][start] == arr[n-1][start]) {
  		  start++;
  	}
  
  	if(start == 0) return "-1";
  	return arr[0].substr(0,start);
}

// T : O(Log N)
// S : O(1)


/*
   Time Complexity  : O(n*m)
   Space Complexity : O(m)

   where 'n' is the size of 'arr' and 'm' is the maximum length of 'arr[i]'.
*/

// Function to find the common prefix of two strings.
string com_prefix(string out1, string out2) {
	  string out;
	  int n1 = out1.length(), n2 = out2.length();
	  for (int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
		    if (out1[i] != out2[j]) {
			      break;
		    }
		    out.push_back(out1[i]);
	  }
	  return out;
}

string commonPrefix(vector<string> &arr, int n) {
	  string prefix = arr[0];

  	// Iterating over all the strings and finding the common prefix.
  	for (int i = 1; i < n; i++) {
  		  prefix = com_prefix(prefix, arr[i]);
  	}
  
  	// Base case of no common prefix.
  	if (prefix == "") {
  		  return "-1";
  	}
  
  	return prefix;
}
