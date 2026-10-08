class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Create buckets
        vector<vector<int>> buckets(nums.size() + 1);
        
        for (auto& entry : freq) {
            int frequency = entry.second;
            int number = entry.first;
            buckets[frequency].push_back(number);
        }
        
        // Step 3: Collect top k
        vector<int> result;
        
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        
        return result;
    }
};