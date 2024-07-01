class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() <= 2)
            return false;

        bool ans = false;
        for(int i = 0; i < (int)arr.size()-2 && !ans;++i)
            ans = IsConsecutiveOdds(arr,i);

        return ans;    
    }

    bool IsConsecutiveOdds(vector<int>& arr, int i)
    {
        if(i+2>=arr.size() || i < 0)
            return false;

        return arr[i]%2 != 0 && arr[i+1]%2 != 0 && arr[i+2]%2 != 0;
    }
};