#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int x[4] = {0,1,0,-1}, y[4] = {1,0,-1,0};

int main(){
    /*
     * 13:10 시작
     * 13:33 끝
     */
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int M, N;
    cin >> M >> N;

    priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> pq;
    vector<vector<int>> board(M+2,vector<int>(N+2,0));
    vector<vector<int>> memoi(M+2,vector<int>(N+2,0));
    memoi[1][1] = 1;

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
            pq.push({board[i][j],i,j});
        }
    }
    while(!pq.empty()){
        vector<int> tmpP = pq.top(); pq.pop();
        for(int i = 0; i < 4; i++){
            if(board[tmpP[1]][tmpP[2]] > board[tmpP[1]+x[i]][tmpP[2]+y[i]])
                memoi[tmpP[1]+x[i]][tmpP[2]+y[i]] += memoi[tmpP[1]][tmpP[2]];
        }
    }

    cout << memoi[M][N] << endl;
    return 0;
}
