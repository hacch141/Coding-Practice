// Set the rightmost unset bit

class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int a = N;
        int pos = 0;
        while(a) {
            if((a&1) == 0) {
                break;
            }
            pos++;
            a = a>>1;
        }
        if(a != 0) {
            N = N | (1<<pos);
        }
        return N;
    }
};

// T : O(Log N)
// S : O(1)
