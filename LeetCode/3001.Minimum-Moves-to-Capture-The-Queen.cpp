// 3001. Minimum Moves to Capture The Queen

class Solution {
public:

    bool is_between(int a, int b, int c) {
        return (abs(b-c) < abs(a-c) && abs(b-a) < abs(a-c));
    }

    bool is_cross(int a, int b, int c) {
        return ((a < b && b < c) || (a > b && b > c));
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if((a == e || b == f)) {
            if( (a == c || b == d) && (is_between(a, c, e) || is_between(b, d, f)) ) {
                return 2;
            }
            return 1;
        }
        if((c + d == e + f)) {
            if( ((a + b == e + f)) && (is_cross(c, a, e) || is_cross(d, b, f)) ) {
                return 2;
            }
            return 1;
        }
        if((c - d == e - f)) {
            if( (a - b == e - f) && (is_cross(c, a, e) || is_cross(d, b, f))) {
                return 2;
            }
            return 1;
        }
        return 2;
    }
};




class Solution {
public:

    bool is_between(int a, int b, int c) {
        return (b-a) * (b-c) < 0;
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if((a == e || b == f)) {
            if(a == e && a == c && is_between(b,d,f)) return 2;
            if(b == f && b == d && is_between(a,c,e)) return 2;
            return 1;
        }
        if(abs(c-e) == abs(d-f)) {
            if(abs(a-e) == abs(b-f) && is_between(c,a,e) && is_between(d,b,f)) return 2;
            return 1;
        }
        return 2;
    }
};
