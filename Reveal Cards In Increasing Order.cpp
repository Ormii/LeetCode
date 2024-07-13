class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size());
        queue<int> que;
        for(int i = 0; i < deck.size(); ++i)
            que.push(i);

        for(int i = 0; i < deck.size() && !que.empty(); ++i)
        {
            int idx = que.front();
            que.pop();

            ans[idx] = deck[i];

            if(!que.empty())
            {
                int nextIdx = que.front();
                que.push(nextIdx);
                que.pop();
            }
        }

        return ans;
    }
};