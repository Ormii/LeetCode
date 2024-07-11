class Solution {
    vector<int> prefixSum;
    int WeightSum;
public:
    Solution(vector<int>& w) {
        WeightSum = 0;
        for(auto& weight : w)
        {
            WeightSum += weight;
            prefixSum.push_back(WeightSum);
        }
    }
    
    int pickIndex() {
        int ind = rand()%prefixSum.back();
        return upper_bound(prefixSum.begin(), prefixSum.end(), ind) - prefixSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */