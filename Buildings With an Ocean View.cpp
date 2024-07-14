class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        stack<int> monotonicStack;
        for(int i = 0; i < heights.size(); ++i)
        {
            while(!monotonicStack.empty() && heights[monotonicStack.top()] <= heights[i])
                monotonicStack.pop();

            monotonicStack.push(i);
        }

        while(!monotonicStack.empty())
        {
            ans.push_back(monotonicStack.top());
            monotonicStack.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};