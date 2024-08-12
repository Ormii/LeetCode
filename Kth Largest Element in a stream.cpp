class KthLargest {
    multiset<int> ms;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k - 1;
        for(auto& num : nums)
            ms.insert(num);
    }
    
    int add(int val) {
        ms.insert(val);

        auto iter = ms.rbegin();
        for(int i = 0; i < kth; ++i)
            iter++;
        
        int result = *iter;

        return result;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */