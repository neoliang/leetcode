class Solution {
public:
    struct Pos{
        Pos():row(0),col(0){}
        Pos(int r,int c):row(r),col(c){}
        int row;
        int col;
    };
    struct Board
    {
        int _size ;
        Board(int s=0)
        :_size(s)
        {
            state.resize(s);
            for(int i=0;i<state.size();++i)
            {
                state[i].resize(s,Empty);
            }
            
        }
        enum {
            Empty = '.',
            HasQueen = 'Q',
            Danger = 'K',
        };
        void Out(ostream& ost)
        {
            for(int i = 0;i<state.size();++i)
            {
                ost << state[i] << endl;
            }
        }
        static bool eq (const Board&l, const Board& other)
        {
            for(int i = 0;i<l.state.size();++i)
            {
                if(l.state[i] !=  other.state[i])
                    return false;
            }
            return true;
        }
        
        static bool less(const Board&l,const Board& other)
        {
            string a ;
            string b;
            for(int i = 0;i<l.state.size();++i)
            {
                a += l.state[i];
                b += other.state[i];
            }
            return a < b;
        }
        bool operator <(const Board& other)const
        {
            return less(*this,other);
        }
        
        vector<string> toStrings()const
        {
            vector<string> result;
            for(int i=0;i<_size;++i)
            {
                string row = state[i];
                for(auto iter = row.begin();iter != row.end();++iter)
                {
                    if(*iter == Danger)
                    {
                        *iter = Empty;
                    }
                }
                result.push_back(row);
            }
            return result;
        }
        void updateDanger(int row,int col,bool d= true)
        {
            char s = Danger;
            if(! d)
            {
                s = Empty;
            }
            for(int i=0;i<_size;++i)
            {
                if(i != col){
                    state[row][i] = s;
                }
                if(i != row)
                {
                    state[i][col] = s;
                }
            }
            //ld
            int i = row;
            int j = col;
            while(++i<_size && --j >= 0)
            {
                state[i][j] = s;
            }
            //lu
            i = row;
            j = col;
            while(--i >= 0 && --j >= 0)
            {
                state[i][j] = s;
            }
            //rd
            i = row;
            j = col;
            while(++i<_size && ++j < _size)
            {
                state[i][j] = s;
            }
            //ru
            i = row;
            j = col;
            while(--i >=0 && ++j < _size)
            {
                state[i][j] = s;
            }
            
        }
        bool putQueen(int row,int col)
        {
            if(state[row][col]==Empty)
            {
                state[row][col] = HasQueen;
                updateDanger(row,col);
                return true;
            }
            return false;
        }
        bool rmQueen(int row,int col)
        {
            if(state[row][col]==HasQueen)
            {
                state[row][col] = Empty;
                updateDanger(row,col,false);
                return true;
            }
            return false;
        }
        
        vector<Pos> AllEmptyPosAtRow(int row)const
        {
            vector<Pos> emptyPoses;
            for(int j = 0;j<state[row].size();++j)
            {
                if(state[row][j]==Empty)
                {
                    emptyPoses.push_back(Pos(row,j));
                }
            }
            return emptyPoses;
        }
        vector<Pos> AllEmptyPos() const
        {
            vector<Pos> emptyPoses;
            for(int i = 0;i<state.size();++i)
            {
                for(int j = 0;j<state[i].size();++j)
                {
                    if(state[i][j]==Empty)
                    {
                        emptyPoses.push_back(Pos(i,j));
                    }
                }
                
            }
            return emptyPoses;
        }
        

    private:
        vector<string> state;
    };
    int _size;
    stack<Board> _stack;
    void solve(vector<vector<string>>& results,int layer =0)
    {
        if(layer >= _size)
        {
            results.push_back(_stack.top().toStrings());
            return;
        }
        
        
        
        vector<Pos> emptyPoses = _stack.top().AllEmptyPosAtRow(layer);
        for(auto iter = emptyPoses.begin();iter != emptyPoses.end();++iter)
        {
            Board next = _stack.top();
            next.putQueen(iter->row, iter->col);
            _stack.push(next);
            solve(results,layer+1);
            _stack.pop();
            
        }
        
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> results;
        _stack = stack<Board>();
        _stack.push(Board(n));
        _size = n;
        solve(results);
        return results;
        
    }
    
};
