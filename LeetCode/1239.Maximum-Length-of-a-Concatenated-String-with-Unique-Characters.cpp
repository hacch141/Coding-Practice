// 1239. Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:
    
    bool compare(vector<int> &selected, string &currStr) {
        vector<int> noRepeat(26,0);
        for(int i=0; i<currStr.length(); i++) {
            if(noRepeat[currStr[i]-'a'] == 1) {
                return false;
            }
            noRepeat[currStr[i]-'a'] = 1;
        }
        
        for(int i=0; i<currStr.length(); i++) {
            if(selected[currStr[i]-'a'] == 1) {
                return false;
            }
        }
        return true;
    }
    
    
    int helper(vector<string>& arr, int i, vector<int>& selected, int len) {
        
        if(i == arr.size()) {
            return len;
        }
        
        string currStr = arr[i];
        if(compare(selected,currStr) == false) {
            return helper(arr,i+1,selected,len);
        }
        else {
            for(int i=0; i<currStr.length(); i++) {
                selected[currStr[i]-'a'] = 1;
            }
            int ans1 = helper(arr,i+1,selected,len+currStr.length());
            
            for(int i=0; i<currStr.length(); i++) {
                selected[currStr[i]-'a'] = 0;
            }
            int ans2 = helper(arr,i+1,selected,len);
            return max(ans1,ans2);
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> selected(26,0);
        return helper(arr,0,selected,0);
    }
};
