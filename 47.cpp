class Solution {
public:
    
    vector<vector<int> > r ;
    void permuteUnique(vector<int> &num,int n) {
        if(n >= num.size())
        {
            r.push_back(num);
        }
        else
        {
            map<int,bool> swaped;
            for(unsigned int i = n;i<num.size();++i)
            {
                if(swaped.find(num[i]) != swaped.end() )
                {
                    continue;
                }
                swaped.insert(make_pair(num[i],true));
                swap(num[n],num[i]);
                permuteUnique(num,n+1);
                swap(num[n],num[i]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        r.clear();
        permuteUnique(num,0);
        return r;
    }
};