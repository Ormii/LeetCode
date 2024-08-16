class Solution {

    using point = pair<int,int>;
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        vector<point> maxVec, minVec;
        for(int i = 0; i < arrays.size(); ++i)
        {
            maxVec.push_back({arrays[i].back(), i});
            minVec.push_back({arrays[i][0], i});

            sort(maxVec.begin(),maxVec.end(),greater<point>());
            sort(minVec.begin(),minVec.end());

            if(maxVec.size() > 2)
                maxVec.pop_back();

            if(minVec.size() > 2)
                minVec.pop_back();    
        }

        int answer = 0;
        if(maxVec[0].second != minVec[0].second)
            answer = maxVec[0].first - minVec[0].first;
        else
            answer = max(maxVec[0].first - minVec[1].first, maxVec[1].first - minVec[0].first);
        return answer;
    }
};