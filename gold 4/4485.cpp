#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int UNVISITED = 1000000000;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int x[4] = {0,1,0,-1}, y[4] = {1,0,-1,0};

int dijkstra(int N, vvi terrain);

int main(){
    ios_base::sync_with_stdio(0);
    int N, cnt = 0;
    cin >> N;
    while(N){
        int answer = 0;
        cnt++;

        vvi terrain(127,vi(127,0));

        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                cin >> terrain[i][j];


        answer = dijkstra(N,terrain);
        cout << "Problem " << cnt << ": " << answer << "\n";
        cin >> N;
    }

    return 0;
}

int dijkstra(int N, vvi terrain){
    priority_queue<vi,vvi,greater<vi>> pq;
    pq.push({terrain[1][1],1,1});
    vvi cost(127,vi(127,UNVISITED));
    vvi visited(127,vi(127,0));
    for(int i = 0; i <= N+1; i++){
        visited[i][0] = 1;
        visited[0][i] = 1;
        visited[N+1][i] = 1;
        visited[i][N+1] = 1;
    }
    while(!pq.empty()){
        vi current = pq.top(); pq.pop();
        visited[current[1]][current[2]] = 1;
        for(int i = 0; i < 4; i++){
            int nextY = current[1] + y[i], nextX = current[2] + x[i];
            int nextCost = current[0] + terrain[nextY][nextX];
            if(!visited[nextY][nextX]){
                if(cost[nextY][nextX] > nextCost) {
                    cost[nextY][nextX] = nextCost;
                    pq.push({nextCost,nextY,nextX});
                }
            }
        }

        while(!pq.empty()){
            current = pq.top();
            if(!visited[current[1]][current[2]]) break;
            pq.pop();
        }
    }

    return cost[N][N];
}
