class Solution {
public:
    string count(string t)
    {
        string result;
        int num = 1;
        auto iter = t.begin();
        auto next = t.begin()+1;
        for(;;++next)
        {
            if(next == t.end() || *iter != *next)
            {
                result.push_back(num +'0');
                result.push_back(*iter);
                iter = next;
                num = 1;
                if(next == t.end())
                {
                    break;
                }
            }
            else
            {
                ++num;
            }
        }
        return result;
    }
    string countAndSay(int n) {
        if(n <=0)
        {
            return "";
        }
        string start = "1";
        for(int i = 1;i<n;++i)
        {
            start = count(start);
        }
        return start;
    }
};