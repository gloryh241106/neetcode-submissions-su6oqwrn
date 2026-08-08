class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;

        for (int i = 0; i <= heights.length; ++i) {
            int currentHeight = (i == heights.length) ? 0 : heights[i];
            while (!stack.isEmpty() && currentHeight < heights[stack.peek()]) {
                int j = stack.pop();
                int height = heights[j];
                int width = 0;

                if (stack.isEmpty()) 
                    width = i;
                else 
                    width = i - stack.peek() - 1;
                
                maxArea = Math.max(maxArea, height * width);
            }
            
            if (i != heights.length)
                stack.push(i);
        }

        return maxArea;
    }
}
