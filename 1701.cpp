#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> K;

    while(K--){
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adjList(V+1);

        while(E--){
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vector<int> visited(V+1,0);
        queue<int> q;

        bool pos = true;

        for(int i = 1; i <= V; i++){
            if(visited[i]) continue;
            q.push(i); visited[i] = 1;
            while(!q.empty()){
                int tmp = q.front(); q.pop();
                for(auto j : adjList[tmp]){
                    if(visited[j] == visited[tmp]){
                        pos = false; break;
                    }
                    if(!visited[j]){
                        visited[j] = 3 - visited[tmp];
                        q.push(j);
                    }
                }
                if(!pos) break;
            }
        }

        if(pos) cout << "YES" << endl;
        else  cout << "NO" << endl;
    }
    return 0;
}
