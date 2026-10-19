class Solution {
public:
    //M1
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& st : strs) {
            encoded += to_string(st.size()) + "#" + st;
        }
        return encoded;
    }
    //M1
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;                 // end of length prefix
            int len = stoi(s.substr(i, j - i));      // handles multi-digit lengths
            ans.push_back(s.substr(j + 1, len));     // exactly len chars after '#'
            i = j + 1 + len;                         // jump past this string
        }
        return ans;
    }
};
