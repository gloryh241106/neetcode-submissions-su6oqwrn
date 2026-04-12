class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> mp(nums.begin(), nums.end());

        for (int num : nums) {
            if (mp.find(num - 1) == mp.end()) {
                int curr = 1;
                int temp = num;

                while (mp.find(temp + 1) != mp.end()) {
                    curr++;
                    temp++;
                }
                ans = max(ans, curr);
            }
        }

        return ans;
    }
};
