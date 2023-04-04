// counting
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int cnt_0=0, cnt_1=0, cnt_2=0;
        
        for(int i=0; i<n; i++) {
            if(a[i]==0) cnt_0++;
            else if(a[i]==1) cnt_1++;
            else if(a[i]==2) cnt_2++;
        }
        
        for(int i=0; i<cnt_0; i++) a[i] = 0;
        
        for(int i=cnt_0; i<cnt_0+cnt_1; i++) a[i] = 1;
        
        for(int i=cnt_0+cnt_1; i<cnt_0+cnt_1+cnt_2; i++) a[i] = 2;
        
    }
    
};


// three pointers
// Dutch national flag
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int low=0, mid=0, high=n-1;

        while(mid<=high) {

            if(a[mid]==0) {
                swap(a[low],a[mid]);
                low++;
                mid++;
            }

            else if(a[mid]==1) {
                mid++;
            }

            else if(a[mid]==2) {
                swap(a[mid],a[high]);
                high--;
            }
            
        }   
    }
};
