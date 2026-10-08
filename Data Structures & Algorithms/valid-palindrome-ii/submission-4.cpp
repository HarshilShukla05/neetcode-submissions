class Solution {
public:
    bool validPalindrome(string s) {
        if(isPalindrome(s))return true;

        for (int i = 0; i < s.size(); i++) {
            string st = s;      // fresh copy each time
            st.erase(i, 1); 
            if(isPalindrome(st))return true;       
        }
        return false;
    }

    bool isPalindrome(string &s){
        int l = 0, r = s.size() - 1;
        while(l<r){
            if(s[l] != s[r])return false;
        l++;
        r--;
        }
        return true;
    }
};