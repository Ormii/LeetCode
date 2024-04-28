
const int SIZE = 'z' - 'a' + 1;

class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }

    int countVowelSubstrings(string word) {
        int ans = 0;
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        int i,j,k;
        for(i = 0; i < word.length(); i++)
        {
            bool isExist[SIZE] = {false,};
            for(j = i; j < word.length(); j++)
            {
                if(isVowel(word[j]) == false)
                    break;

                isExist[word[j]-'a'] = true;

                if(j - i < 4)
                    continue;

                bool check = true;
                for(int k = 0; k < 5 && check; k++)
                    check = check && isExist[vowels[k] - 'a'];

                if(check)
                    ans++;
            }
        }
    
        return ans;
    }
};