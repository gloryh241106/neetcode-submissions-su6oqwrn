class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int mp = 0;

        while (left < right) {
            mp = max(mp, min(heights[left], heights[right]) * (right - left));

            if (heights[left] < heights[right])
                left++;
            else 
                right--;
        }

        return mp;
    }
};
