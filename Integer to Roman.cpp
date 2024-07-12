class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> Roman;
        Roman.push_back({"M",1000});
        Roman.push_back({"CM",900});
        Roman.push_back({"D",500});
        Roman.push_back({"CD",400});
        Roman.push_back({"C",100});
        Roman.push_back({"XC",90});
        Roman.push_back({"L",50});
        Roman.push_back({"XL",40});
        Roman.push_back({"X",10});
        Roman.push_back({"IX",9});
        Roman.push_back({"V",5});
        Roman.push_back({"IV",4});
        Roman.push_back({"I",1});

        string ans = "";

        for(int i = 0; i < Roman.size(); ++i)
        {
            string RomanChars = Roman[i].first;
            int Value = Roman[i].second;
            int CharCount = num/Value;

            for(int j = 0; j < CharCount; ++j)
                ans.append(RomanChars);

            num%=Value;
        }

        return ans;
    }
};