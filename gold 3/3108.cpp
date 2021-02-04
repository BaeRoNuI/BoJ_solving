#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int x, int y, vector<vector<int>> &board);
int X[4] = {0,1,0,-1}, Y[4] = {1,0,-1,0};

int main(){
    int N;
    cin >> N;
    vector<vector<int>> board(2001,vector<int>(2001,0));

    while(N--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = (x1 +500) * 2;
        x2 = (x2 + 500) * 2;
        y1 = (y1 + 500) * 2;
        y2 = (y2 + 500) * 2;
        for(int i = x1; i <= x2; i++) {
            board[i][y1] = 1;
            board[i][y2] = 1;
        }
        for(int i = y1; i <= y2; i++) {
            board[x1][i] = 1;
            board[x2][i] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            if(board[2 * i][2 * j] == 1){
                dfs(2 * i,2 * j,board);
                ans++;
            }
        }
    }
    if(board[1000][1000] != 0) ans--;

    cout << ans << endl;

    return 0;
}

void dfs(int x, int y, vector<vector<int>> &board){
    board[x][y] = 2;
    for(int i = 0; i < 4; i++){
        int tmpX = x+X[i], tmpY = y+Y[i];
        if(tmpX >=0 && tmpX <= 2000 && tmpY >= 0 && tmpY <= 2000 && board[tmpX][tmpY] == 1){
            dfs(tmpX,tmpY,board);
        }
    }
}
