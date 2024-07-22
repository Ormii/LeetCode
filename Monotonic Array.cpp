class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        stack<int> increaseSt;
        stack<int> decreaseSt;

        bool isIncrease = true, isDecrease = true;
        for(auto& num : nums)
        {
            while(!increaseSt.empty() && increaseSt.top() > num)
            {
                isIncrease = false;
                increaseSt.pop();
            }
            increaseSt.push(num);

            while(!decreaseSt.empty() && decreaseSt.top() < num)
            {
                isDecrease = false;
                decreaseSt.pop();
            }

            decreaseSt.push(num);
        }

        return isIncrease || isDecrease;
    }
};