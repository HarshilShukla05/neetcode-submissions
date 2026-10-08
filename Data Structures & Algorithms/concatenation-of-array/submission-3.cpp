class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n);
        int j = 0;
        for(int i=0 ;i<n ; i++){
            ans[j] = nums[i];
            j++;
        }
        for(int i = 0 ; i<n ; i++){
            ans[j] = nums[i];
            j++;
        }
        return ans;
    }
};