class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Check base case
        if (nums.size() < 3)
            return {};

        // Sort the array first for faster query
        sort(nums.begin(), nums.end());

        // Array for storing result
        vector<vector<int>> mp;

        // Iterate each element from 0 to nums.size() - 2
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Checking if numbers is positive or repeating
            if (nums[i] > 0)
                break;

            if (i && nums[i] == nums[i - 1])
                continue;
            
            // Two pointers technique
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total < 0)
                    left++;
                else if (total > 0)
                    right--;
                else {
                    mp.push_back({nums[i], nums[left], nums[right]});
                    left++;     // Moving on to the next element

                    // Avoid repetition
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
            }
        }

        return mp;
    }
};
