// Swap two numbers

class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        a = a^b;
        b = a^b;
        a = a^b;
        return {a,b};
    }
};

// T : O(1)
// S : O(1)



class Solution{   
public:
    pair<int, int> get(int a, int b){
        //complete the function here
        a = a^b;
        b = a^b;
        a = a^b;
        return {a,b};
    }
};

// T : O(1)
// S : O(1)
