class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        int n = max(num1.size(), num2.size());
        while(num1.size() < n)
            num1.insert(num1.begin(), '0');
        while(num2.size() < n)
            num2.insert(num2.begin(), '0');

        string result = "";
        for(int i = 0; i < n; ++i)
        {
            string temp = "";
            int carry = 0;
            for(int j = 0; j < i; ++j)
                temp +='0';

            for(int j = 0; j < n; ++j)
            {
                int a = num1[n - 1 - i] - '0';
                int b = num2[n - 1 - j] - '0';
                int c = (a*b + carry)%10;
                carry = (a*b + carry)/10;

                temp += c + '0';
            }

            if(carry > 0)
                temp += carry + '0';

            reverse(temp.begin(), temp.end());
            
            int cnt = 0;
            for(int i = 0; i < temp.size(); ++i)
                if(temp[i]!='0')
                    break;
                else
                    cnt++;
            temp = temp.substr(cnt,temp.size()-cnt);

            result = add(result, temp);
        }

        return result;
    }

    string add(string num1, string num2)
    {
        int n = max(num1.size(), num2.size());
        while(num1.size() < n)
            num1.insert(num1.begin(), '0');
        while(num2.size() < n)
            num2.insert(num2.begin(), '0');

        string result = "";
        int carry = 0;
        for(int i = 0; i < n; ++i)
        {
            int a = num1[n-1 -i] - '0';
            int b = num2[n-1 -i] - '0';
            int c = (a+b+carry)%10;
            carry = (a+b+carry)/10;

            result += c + '0';
        }

        if(carry > 0)
            result += carry+'0';

        reverse(result.begin(), result.end());
        int cnt = 0;
        for(int i = 0; i < result.size(); ++i)
            if(result[i]!='0')
                break;
            else
                cnt++;
        result = result.substr(cnt,result.size()-cnt);
        return result;
    }
};