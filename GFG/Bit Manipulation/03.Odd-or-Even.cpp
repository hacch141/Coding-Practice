// Odd or Even

class Solution{   
public:
    string oddEven(int N){
        // code here 
        bool odd = N & 1;
        return odd == true ? "odd" : "even";
    }
};

// T : O(1)
// S : O(1)
