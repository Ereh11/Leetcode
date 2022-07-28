class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0 ; i < 9 ; i++) 
        {
            vector<int> frq(10);
            for(int j = 0 ; j < 9 ; j++)
                if(board[i][j] != '.') 
                {
                    if(!frq[int(board[i][j])-48]) frq[int(board[i][j])-48]++;
                    else return false;
                }
        }
        
       for(int i = 0 ; i < 9 ; i++) 
        {
            vector<int> frq(10);
            for(int j = 0 ; j < 9; j++)
                if(board[j][i] != '.') 
                {
                   if(!frq[int(board[j][i])-48]) frq[int(board[j][i])-48]++;
                    else return false;
                }
        }
        
        
        int row = 0 , col = 0, cnt = 0, rowindex = 0;
        vector<int> frq(10);
        while(row != 9) 
        {
            for(int j = col ; j <= col + 2; j++)
            {
                if(board[rowindex][j] != '.') 
                {
                    if(!frq[int(board[rowindex][j])-48]) frq[int(board[rowindex][j])-48]++;
                    else return false;
                }
                cout<<"\n";
            }
            
            rowindex++,  cnt++;
            
            if(!(cnt % 3)) 
            {
                frq = vector<int>(10);
                if(cnt == 9) row += 3, cnt = col = 0;
                else col += 3, rowindex = row;
            }
        }
        
       return true;
        
    }
};