class Solution {
public:
    int majorityElement(vector<int> &num) {
        stack<int> s;
        for(auto iter = num.begin();iter != num.end();++iter)
        {
            if(s.empty() || s.top() == *iter)
            {
                s.push(*iter);
            }
            else
            {
                s.pop();
            }
        }
        return s.top();
    }
};