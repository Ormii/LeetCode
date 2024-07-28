class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,int> umRank;
        unordered_set<char> usSuit;
        const int n = 5;
        for(int i = 0; i < n; ++i)
        {
            umRank[ranks[i]]++;
            usSuit.insert(suits[i]);
        }

        if(usSuit.size() == 1)
            return "Flush";
        
        int maxCount = 0;
        for(auto& obj : umRank)
            maxCount = max(maxCount, obj.second);
        
        if(maxCount >= 3)
            return "Three of a Kind";
        else if(maxCount >= 2)
            return "Pair";
        else
            return "High Card";

    }
};