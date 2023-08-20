// Lemonade Change

bool lemonadeChange(vector<int> &bill) {
  	// Write your code here.
  	int cnt20=0, cnt10=0, cnt5=0;
  	for(auto i : bill) {
    		if(i==5) {
    			  cnt5++;
    		}
    		else if(i==10) {
      			if(cnt5<=0) return false;
      			cnt5--;
      			cnt10++;
    		}
    		else if(i==20) {
      			if(cnt5>0 && cnt10>0) {
        				cnt5--;
        				cnt10--;
        				cnt20++;
      			}
      			else if(cnt5>=3) {
        				cnt5 -= 3;
        				cnt20++;
      			}
      			else {
      				  return false;
      			}
    		}
  	}
  	return true;
}
// T : O(N)
// S : O(1)
