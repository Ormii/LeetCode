class Solution {
public:
    int countSeniors(vector<string>& details) {
        int answer = 0;
        for(auto& detail : details)
        {
            string age = detail.substr(11,2);
            if(stoi(age) > 60)
                answer++;
        }

        return answer;
    }
};