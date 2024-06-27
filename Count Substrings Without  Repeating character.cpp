class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int prev=0, count=0;

        vector<int> hash(26,0);

        for(int i=0;i<s.size();i++){


            hash[s[i]-'a']++;

            while(hash[s[i]-'a']>1 && prev<i){

                hash[s[prev]-'a']--; prev++;
            }

            count+=(i-prev+1);
        }

        return count;
    }
};