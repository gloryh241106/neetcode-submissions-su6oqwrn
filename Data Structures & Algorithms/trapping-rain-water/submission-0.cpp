class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        int total_water = 0;
        int left = 0, right = height.size() - 1;
        int max_left = height[left], max_right = height[right];

        while (left < right) {
            if (max_left < max_right) {
                left++;
                max_left = max(max_left, height[left]);
                total_water += max_left - height[left];
            }
            else {
                right--;
                max_right = max(max_right, height[right]);
                total_water += max_right - height[right];
            }
        }

        return total_water;
    }
};
