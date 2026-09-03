class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left = 0, right = 0, maxSize = 0;

        while (right < s.size()) {
            freq[s[right] - 'a']++;

            while (freq[s[right] - 'a'] > 1)
                freq[s[left++] - 'a']--;

            maxSize = max(maxSize, right - left + 1);
            right++;
        }

        return maxSize;
    }
};
