class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int maxPiles = 0;
        for (int pile : piles)
            maxPiles = Math.max(maxPiles, pile);

        int left = 1, right = maxPiles;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long totalHours = 0;

            for (int pile : piles) 
                totalHours += (pile + mid - 1) / mid;

            if (totalHours <= h) 
                right = mid;
            else 
                left = mid + 1;
        }

        return left;
    }
}
