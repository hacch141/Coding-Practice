// 509. Fibonacci Number

class Solution
{
public:
    int fib(int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (n == 1 || n == 0) {
            return n;
        }
        else {
            int a = 0, b = 1, c = 1;
            for (int i = 2; i <= n; i++) {
                c = a + b;
                a = b;
                b = c;
            }
            return c;
        }
        return -1;
    }
};
