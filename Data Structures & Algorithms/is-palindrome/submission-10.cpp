class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = (int)s.size() - 1;

        while (l < r) {
            // skip non-alphanumeric from the left
            while (l < r && !isalnum((unsigned char)s[l])) l++;
            // skip non-alphanumeric from the right
            while (l < r && !isalnum((unsigned char)s[r])) r--;

            if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r]))
                return false;

            l++;
            r--;
        }
        return true;
    }
};