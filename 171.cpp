class Solution {
public:
    int titleToNumber(string s) {
        if (s.size() ==0) return 0;
        if (s.size()==1) return s[0]-'A'+1;
        int result = s[0]-'A'+1;
        for(int i= 1; i< s.size();++i)
        {
            result *= 26;
            result += (s[i]-'A'+1);
        }
        return result;
    }
};