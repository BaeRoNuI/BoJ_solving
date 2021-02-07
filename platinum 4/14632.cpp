#include <iostream>
#include <string>
using namespace std;

char drawing[1000][1000];
int N, M, K;
string stamp[500][500];
pair<int,int> stampSize[500];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            drawing[i][j] = '.';

    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> stampSize[i].first >> stampSize[i].second;
        for(int j = 0; j < stampSize[i].first; j++){
            cin >> stamp[i][j];
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int t, y, x, stampY, stampX;
        cin >> t >> y >> x; t--;
        stampY = stampSize[t].first;
        stampX = stampSize[t].second;
        for(int i = y; i < y + stampY && i < N; i++){
            for(int j = x; j < x + stampX && j < M; j++){
                drawing[i][j] = stamp[t][i-y][j-x];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << drawing[i][j];
        } cout << endl;
    }

    return 0;
}
