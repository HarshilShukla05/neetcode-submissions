class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res =0;;
        for(int i=0 ; i<nums.size() ; i++){
            int c=0;
            for(int k = i ; k<nums.size() ; k++){
                if(nums[k] == 0)break;
                c++;
            }
            res = max(res, c);
        }
        return res;
    }
};