public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // Set nums1.length < nums2.length
        if (nums1.length > nums2.length)
            return findMedianSortedArrays(nums2, nums1);

        int[] A = nums1;
        int[] B = nums2;

        int m = A.length, n = B.length;
        int leftSide = (m + n + 1) / 2;

        int left = 0, right = m;
        while (left <= right) {
            int cutA = left + (right - left) / 2;
            int cutB = leftSide - cutA;

            // Four boundary values
            int Aleft = (cutA == 0) ? Integer.MIN_VALUE : A[cutA - 1];
            int Aright = (cutA == m) ? Integer.MAX_VALUE : A[cutA];
            int Bleft = (cutB == 0) ? Integer.MIN_VALUE : B[cutB - 1];
            int Bright = (cutB == n) ? Integer.MAX_VALUE : B[cutB];

            // Is the partition valid?
            if (Aleft <= Bright && Bleft <= Aright) {

                // odd total
                if ((m + n) % 2 == 1)
                    return Math.max(Aleft, Bleft);

                // even total
                return (Math.max(Aleft, Bleft) + Math.min(Aright, Bright)) / 2.0;
            }

            // cutA is too far right
            else if (Aleft > Bright) 
                right = cutA - 1;

            // cutA is too far left
            else 
                left = cutA + 1;
        }

        return 0.0;
    }
}