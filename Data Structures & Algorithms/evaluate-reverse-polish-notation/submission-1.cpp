class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

                int res;

                if (s == "+") 
                    res = num1 + num2;
                else if (s == "-")
                    res = num1 - num2;
                else if (s == "*") 
                    res = num1 * num2;
                else if (s == "/") 
                    res = num1 / num2;

                nums.push(res);
            }
            else 
                nums.push(stoi(s));
        }

        return nums.top();
    }
};
