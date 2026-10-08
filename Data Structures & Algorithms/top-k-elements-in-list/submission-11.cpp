class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
    for (auto n : nums) {
      mp[n]++;
    }
    vector<pair<int, int>>freq(mp.begin(), mp.end());
    sort(freq.begin(), freq.end(), [](auto& a, auto& b) {
        return a.second > b.second;  // sort by count descending
    });

    vector<int>ans;
    for(int i=0 ; i<k ; i++){
      ans.push_back(freq[i].first);
    }
    return ans;

    }
};
