class Solution {
public:
    bool isValid(vector<string>& board,int x,int y,int n){
        // upper left diagonal
        int i=x-1,j=y-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')return false;
            i--,j--;
        }

        i=x+1,j=y-1;

        while(i<n && j>=0){
            if(board[i][j]=='Q')return false;
            i++,j--;
        }

        // left side

        i=x,j=y-1;
        while(j>=0){
            if(board[i][j]=='Q')return false;
            j--;
        }

        return true;
    }
    void solve(int col,vector<vector<string>>& ans,vector<string>& board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isValid(board,i,col,n)){
                board[i][col]='Q';
                solve(col+1,ans,board,n);
                board[i][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        solve(0,ans,board,n);
        return ans;
    }
};