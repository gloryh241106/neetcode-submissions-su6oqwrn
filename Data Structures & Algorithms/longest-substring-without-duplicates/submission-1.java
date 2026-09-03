class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> freq = new HashMap<>();
        int left = 0, right = 0, maxSize = 0;
        
        while (right < s.length()) {
            char c = s.charAt(right);
            freq.put(c, freq.getOrDefault(c, 0) + 1);

            while (freq.get(c) > 1) {
                char leftChar = s.charAt(left);
                freq.put(leftChar, freq.get(leftChar) - 1);
                left++;
            }

            maxSize = Math.max(maxSize, right - left + 1);
            right++;
        }

        return maxSize;
    }
}
