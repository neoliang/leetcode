class Solution {
public:
    bool isPalindrome(string s) {
        string minS;
        for(auto i = s.begin(); i != s.end();++i) if(isalnum(*i)) minS.push_back(tolower(*i));
        string rs = minS;
        reverse(rs.begin(), rs.end());
        return rs == minS;
    }
};