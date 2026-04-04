class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto p : mp) 
            bucket[p.second].push_back(p.first);

        vector<int> res;
        for (int i = nums.size(); i >= 0; --i) {
            for (int j : bucket[i]) {
                res.push_back(j);
                k--;

                if (k == 0) 
                    return res;
            }
        }

        return res;
    }
};
