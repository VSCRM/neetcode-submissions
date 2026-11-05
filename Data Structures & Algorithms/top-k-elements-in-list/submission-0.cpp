class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (const auto& [num, cnt] : count)
            freq[cnt].push_back(num);

        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; --i) {
            for (int num : freq[i]) {
                res.push_back(num);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
