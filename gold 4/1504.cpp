#include <iostream>
#include <vector>
#include <queue>
#define UNVISITED 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<ll> dijkstra(int start, vector<vector<pii>> adjList){
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    int vertex = adjList.size();
    vector<int> visited(vertex+1,0);
    vector<ll> length(vertex+1,UNVISITED);
    pq.push({0,start}); length[start] = 0;
    while(!pq.empty()){
        pair<int,int> ptmp = pq.top();
        pq.pop();
        int tmp = ptmp.second;
        visited[tmp] = 1;
        for(int i = 0; i < adjList[tmp].size(); i++){
            int node = adjList[tmp][i].first, l = adjList[tmp][i].second;
            if(!visited[node]){
                if(length[node] > length[tmp] + l) {
                    length[node] = length[tmp] + l;
                    pq.push({length[node],node});
                }
            }
        }
    }
    return length;
}

int main(){
    ios_base::sync_with_stdio(0);
    int N, E;
    cin >> N >> E;
    vector<vector<pair<int,int>>> adjList(N+1);
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }
    int a, b;
    cin >> a >> b;

    vector<ll> startAtS, startAtA, startAtB;
    startAtS = dijkstra(1,adjList);
    startAtA = dijkstra(a,adjList);
    startAtB = dijkstra(b,adjList);

    ll answer = 0;
    // plan 1 : s -> a -> b -> N
    ll p11 = startAtS[a], p12 = startAtA[b], p13 = startAtB[N];
    if(p11 != UNVISITED && p12 != UNVISITED && p13 != UNVISITED){
        answer = p11 + p12 + p13;
    }

    // plan 1 : s -> b -> a -> N
    ll p21 = startAtS[b], p22 = startAtB[a], p23 = startAtA[N];
    if(p21 != UNVISITED && p22 != UNVISITED && p23 != UNVISITED){
        answer = answer > p21 + p22 + p23 ? p21 + p22 + p23 : answer;
    }
    if(!answer) answer = -1;
    cout << answer << endl;
    return 0;
}