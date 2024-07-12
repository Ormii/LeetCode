class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string HeightPriorityChars = (x > y) ? "ab" : "ba";
        string LowPriorityChars = (HeightPriorityChars == "ab") ? "ba" : "ab";

        int ans = 0;
        string RemoveHeightPriority = RemoveSubString(s, HeightPriorityChars);
        int RemoveCount = (s.length() - RemoveHeightPriority.length())/2;

        ans += (RemoveCount)*max(x,y);

        string RemoveLowPriority = RemoveSubString(RemoveHeightPriority, LowPriorityChars);
        RemoveCount = (RemoveHeightPriority.length() - RemoveLowPriority.length())/2;

        ans += (RemoveCount)*min(x,y);

        return ans;
    }
public:
    string RemoveSubString(const string& input, const string& target)
    {
        stack<char> st;
        for(char currentChar : input)
        {
            if(currentChar == target[1] && !st.empty() && st.top() == target[0])
                st.pop();
            else
                st.push(currentChar);
        }

        string RemainString = "";
        while(!st.empty())
        {
            RemainString += st.top();
            st.pop();
        }

        reverse(RemainString.begin(), RemainString.end());
        return RemainString;
    }
};