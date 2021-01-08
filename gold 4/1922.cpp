#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll answer = 0;
    cin >> N >> M;

    vvvi adjList(N+1);

    int min = 1000000, tmp1, tmp2;
    while(M--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b) continue;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
        if(c < min){
            min = c; tmp1 = a; tmp2 = b;
        }
    }
    vi visited(N+1,0);

    priority_queue<vi,vvi,greater<vi>> pq;
    pq.push({min,tmp1,tmp2});
    int cnt = 0;

    while(!pq.empty()){
        vi tmp = pq.top();
        int a = tmp[1], b = tmp[2], c = tmp[0];
        if(!visited[a]){
            cnt++; visited[a] = 1;
        }
        if(!visited[b]){
            cnt++; visited[b] = 1;
        }
        answer += c;
        for(int i = 0; i < adjList[a].size(); i++){
            int nextNode = adjList[a][i][0];
            if(visited[nextNode]) continue;
            int nextCost = adjList[a][i][1];
            pq.push({nextCost,nextNode,a});
        }
        for(int i = 0; i < adjList[b].size(); i++){
            int nextNode = adjList[b][i][0];
            if(visited[nextNode]) continue;
            int nextCost = adjList[b][i][1];
            pq.push({nextCost,nextNode,b});
        }
        while(!pq.empty()){
            tmp = pq.top();
            if(!visited[tmp[1]] || !visited[tmp[1]]) break;
            pq.pop();
        }
        if(cnt >= N) break;
    }

    cout << answer << endl;
    return 0;
}
