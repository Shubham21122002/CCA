#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row, int col, vector<string> &board, int n) {

}
int solve(int col, vector<string> &board,vector<vector<string>> ans, int n) {
    //base cond
    if(col==n) {
        ans.push_back(board);
        return;
    }
    
    for(int row = 0 ; row < n ; row++) {
        if(isSafe(row,col,board,n)) {
            board[row][col] = 'Q';
            solve(col+1, board,ans,n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueen(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0 ; i < n ; i++ ) {
        board[i] = s;
    }
   solve(0, board, ans, n);
   return ans;
}
int main()
{
    int n;
    cout<<"Enter the size of board : ";
    cin>>n;
    vector<vector<string>> ans = solveNQueen(n);


 return 0;
}