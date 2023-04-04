class Solution{
  public:
  
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ele = 0;
        int cnt = 0;

        for(int i=0; i<size; i++) {

            if(cnt == 0) {
                ele = a[i];
                cnt++;
            }

            else if(a[i] == ele) {
                cnt++;
            }

            else {
                cnt--;
            }
            
        }

        int freq = 0;
        for(int i=0; i<size; i++) {
            if(a[i] == ele) freq++;
        }

        if(freq > size/2) return ele;

        return -1;

        
    }
};
