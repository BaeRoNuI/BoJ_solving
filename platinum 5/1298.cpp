#include <iostream>
#include <vector>
#define MAX 5005
using namespace std;
typedef vector<int> vi;

bool dfs(int x, vi &newHost, vector<bool> &taken, vector<vi> adjList);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vi newHost(MAX,0);

    vector<vi> adjList(N+1);
    for(int i = 0; i < M; i++){
        int tmpA, tmpB;
        cin >> tmpA >> tmpB;
        adjList[tmpA].push_back(tmpB);
    }

    int cnt = 0;
    vector<bool> taken;
    for(int i = 1; i <= N; i++){
        taken.assign(MAX,0);
        if(dfs(i,newHost,taken,adjList)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

bool dfs(int x, vi &newHost, vector<bool> &taken, vector<vi> adjList){
    for(int i = 0; i < adjList[x].size(); i++){
        int tmp = adjList[x][i];
        if(taken[tmp]) continue; taken[tmp] = 1;
        if(newHost[tmp] == 0 || dfs(newHost[tmp],newHost,taken,adjList)){
            newHost[tmp] = x;
            return true;
        }
    } return false;
}
