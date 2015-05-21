class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n>0)
        {
            n -= 1;
            char c = n % 26 + 'A';
            s.push_back(c);
            n /= 26;
        }
        return string(s.rbegin(),s.rend());
    }
};