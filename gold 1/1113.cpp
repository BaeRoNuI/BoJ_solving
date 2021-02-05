#include <iostream>
using namespace std;

int N, M;
int floor[52][52] = {0,}, visited[52][52] = {0,};
int x[4] = {0,1,0,-1}, y[4] = {1,0,-1,0};

void clearVisited(){
    for(int i = 0; i <= N+1; i++){
        for(int j = 0; j <= M+1; j++){
            visited[i][j] = 0;
        }
    }
}

int dfs(int X, int Y, int height){
    if(X < 1 || X > N || Y < 1 || Y > M || !floor[X][Y]) return -250001;
    if(visited[X][Y]) return 0;
    visited[X][Y] = 1;
    if(height <= floor[X][Y]) return 0;
    int ans = 1;
    for(int i = 0; i < 4; i++){
        ans += dfs(X+x[i],Y+y[i],height);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> c;
            floor[i][j] = c - '0';
        }
    }

    int ans = 0;

    for(int k = 1; k < 10; k++){
        clearVisited();
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(!visited[i][j] && floor[i][j] < k){
                    int tmp = dfs(i,j,k);
                    if(tmp > 0) ans += tmp;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
