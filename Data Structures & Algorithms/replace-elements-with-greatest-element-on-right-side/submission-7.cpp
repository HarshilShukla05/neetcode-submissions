class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>res(n);
        int rm = -1;
        for(int i = arr.size()-1 ; i >= 0 ; --i){
            res[i] = rm;
            rm = max(rm , arr[i]);
        }
        return res;
    }
};