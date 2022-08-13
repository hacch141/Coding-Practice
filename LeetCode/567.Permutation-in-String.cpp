// 567. Permutation in String

class Solution {
public:
    
    bool aresame(int CT[], int CP[]) {
        for(int i=0; i<256; i++) {
            if(CT[i] != CP[i]) {
                return false;
            }
        }
        return true;
    }

    const int CHAR = 256;
	bool checkInclusion(string s1, string s2) {
	    // code here
	    if(s1.length() > s2.length()) {
	        return false;
	    }

	    int CT[256] = {0};
	    int CP[256] = {0};
	    for(int i=0; i<s1.length(); i++) {
	        CT[s2[i]]++;
	        CP[s1[i]]++;
	    }

	    int ans = 0;
	    for(int i=s1.length(); i<s2.length(); i++) {
	        if(aresame(CT,CP)) {
	            return true;
	        }
	        CT[s2[i]]++;
	        CT[s2[i-s1.length()]]--;
	    }
	    if(aresame(CT,CP)) {
	        return true;
	    }
	    return false;
	}
};
