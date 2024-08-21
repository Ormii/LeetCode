class Solution {
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int n = s.length();
        
        vector<vector<int>> minTurns(n, vector<int>(n,0));
        for(int i = 0; i < n; ++i)
            minTurns[i][i] = 1;
        
        for(int length = 2; length <= n; ++length)
        {
            for(int start = 0; start+length-1 < n; ++start)
            {
                int end = start+length-1;
                minTurns[start][end] = length;
                
                for(int split = 0; split < length - 1; ++split)
                {
                    int totalTurns = minTurns[start][start + split] + minTurns[start + split + 1][end];
                    if(s[start + split] == s[end])
                        totalTurns--;
                    
                    minTurns[start][end] = min(minTurns[start][end], totalTurns);
                }
            }
        }
        
        int answer = minTurns[0][n-1];
        return answer;
    }

    string removeDuplicates(string& s)
    {
        string uniqueChars;
        int i = 0;
        while(i < s.length())
        {
            char currentChar = s[i];
            uniqueChars += currentChar;
            while(i < s.length()&& currentChar == s[i])
                i++;
        }

        return uniqueChars;
    }
};