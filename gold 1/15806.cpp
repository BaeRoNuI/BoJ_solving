#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int x[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int y[8] = { 1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    int N, M, K, t;
    cin >> N >> M >> K >> t;

    vector<vector<vector<bool>>> room(N+1, vector<vector<bool>>(N+1,vector<bool>(2,false)));
    queue<pair<int,int>> q;

    int tmpX, tmpY, current = 0;
    while(M--){
        cin >> tmpX >> tmpY;
        q.push({tmpX,tmpY});
        room[tmpX][tmpY][current] = true;
    }

    for(int i = 0; i < t; i++){
        int s = q.size(); current = 1 - current;
        while(s--){
            pair<int,int> p = q.front(); q.pop();
            for(int j = 0; j < 8; j++){
                tmpX = p.first + x[j];
                tmpY = p.second + y[j];
                if(tmpX > 0 && tmpY <= N && tmpY > 0 && tmpX <= N){
                    if(!room[tmpX][tmpY][current]){
                        room[tmpX][tmpY][current] = true;
                        q.push({tmpX,tmpY});
                    }
                }
            }
        }
    }

    current = t % 2;
    bool pos = false;
    while(K--){
        cin >> tmpX >> tmpY;
        if(room[tmpX][tmpY][current]){
            pos = true;
            break;
        }
    }

    if(pos) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
