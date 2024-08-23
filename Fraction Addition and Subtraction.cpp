class Solution {
public:
    void add(int child, int parent, bool isMinus, int otherChild, int otherParent,
    int& outChild, int& outParent)
    {
        outParent = parent * otherParent;
        outChild = child*otherParent + ((isMinus)? -otherChild*parent : otherChild*parent);

        int c = gcd(outParent, outChild);
        outChild /= c;
        outParent /= c;
    }

    string fractionAddition(string expression) {
        
        int child = 0, parent = 1;
        int otherChild = 0, otherParent = 1;
        bool isMinus = false;
        string nums = "";
        for(auto& c : expression)
        {
            if(!isdigit(c))
            {
                if(c == '-' || c == '+')
                {
                    if(nums.size() > 0)
                        otherParent = stoi(nums);
                    nums.clear();

                    add(child, parent, isMinus, otherChild, otherParent, child, parent);
                    if(c == '-')
                        isMinus = true;
                    else if(c == '+')
                        isMinus = false;
                    
                }
                else if(c == '/')
                {
                    if(nums.size() > 0)
                        otherChild = stoi(nums);
                    nums.clear();
                }
            }
            else
            {
                nums += c;
            }
        }

        if(nums.size() > 0)
            otherParent = stoi(nums);
        nums.clear();
                    
        add(child, parent, isMinus, otherChild, otherParent, child, parent);
        
        string answer = "";
        answer.append(to_string(child));
        answer += '/';
        answer.append(to_string(parent));

        return answer;
    }
};