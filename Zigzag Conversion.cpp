class Solution {
public:
    string convert(string s, int numRows) {
        vector<tuple<int,int,char>> v;
        
        int rows = 0;
        int cols = 0;
        bool dirDown = true;
        for(int i = 0; i < s.size(); ++i)
        {
            v.push_back({rows,cols,s[i]});
            if(dirDown && (rows == numRows - 1))
                dirDown = false;
            else if(rows == 0)
                dirDown = true;

            if(dirDown)
            {
                rows = min(numRows - 1,rows+1);
                if(numRows == 1)
                    cols++;
            }
            else
            {
                cols++;
                rows = max(0, rows-1);
            }
        }

        sort(v.begin(),v.end(),[&](tuple<int,int,char>& obj1, tuple<int,int,char>& obj2)->bool{
            if(get<0>(obj1) < get<0>(obj2))
                return true;
            else if(get<0>(obj1)==get<0>(obj2) && get<1>(obj1) < get<1>(obj2))
                return true;

            return false;
        });

        string answer = "";
        for(auto& obj : v)
            answer += get<2>(obj);

        return answer;
    }
};