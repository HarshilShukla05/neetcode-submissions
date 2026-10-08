class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0 , j = 0;
        bool ans = true;
        while(i<s.size() && j < t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
            }else j++;
        }
        if(i < s.size() && j >= t.size())ans = false;
        return ans;
    }
};