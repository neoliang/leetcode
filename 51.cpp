class Solution {
public:
    int _n;
    vector<vector<string>> results;

    bool sameDiag(int row1,int col1,int row2,int col2)
    {
        return abs(row1-row2) == abs(col1 - col2);
    }
    bool sameDiags(int maxRow,const std::vector<int>& xs)
    {
        for (int i=0; i<maxRow; ++i) {
            if (sameDiag(i, xs[i], maxRow, xs[maxRow])) {
                return true;
            }
        }
        return false;
    }
    void prem(unsigned i,std::vector<int> xs)
    {
        if (i >=_n) {
            std::vector<string> rows;
            toString(xs, rows);
            results.push_back(rows);
        }
        else
        {
            for (unsigned int j =i; j<xs.size(); ++j) {
                std::swap(xs[i], xs[j]);
                if (!sameDiags(i, xs)) {
                    
                    prem(i+1, xs);
                    
                }
                std::swap(xs[i], xs[j]);
                
            }
        }
    }

    void queens()
    {
        std::vector<int> can;
        for (int i =1; i<=_n; ++i) {
            can.push_back(i);
        }
        prem(0, can);
    }
    void toString(std::vector<int>& ls,vector<string>& rows)
    {
        for (int row=0; row<ls.size(); ++row) {
            std::string rowStr;
            for (int col=0; col<ls.size(); ++col) {
                if (ls[row] == col +1 ) {
                    rowStr.push_back('Q');
                }
                else
                {
                    rowStr.push_back('.');
                }
            }
            rows.push_back(rowStr);
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        results.clear();
        _n = n;
        queens();
        return results;
    }
};
