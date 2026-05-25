class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> mp;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0)
                break;
            
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total < 0)
                    left++;
                else if (total > 0)
                    right--;
                else {
                    mp.push_back({nums[i], nums[left], nums[right]});
                    left++;

                    while (left < right && nums[left] == nums[left - 1])   
                        left++;
                }
            }
        }

        return mp;
    }
};
