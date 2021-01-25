#include<iostream>
#include<vector>
using namespace std;

void solution(vector<int> v, vector<int> &memoi);
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    // v에는 수열A를 저장, memoi[i]는 i번째 수가 들어간 lis를 찾을때 lis 수열에서의 바로 전 위치 저장
    vector<int> v(N), memoi(N,-1);
    for(int i = 0; i < N; i++)  cin >> v[i];

    solution(v,memoi);

    return 0;
}

void solution(vector<int> v, vector<int> &memoi){
    // ans[i]에 i번째 수가 들어가는 lis의 최대 길이
    vector<int> ans(N,1);
    int ansInx = -1, ansSize = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && ans[j]+1 > ans[i]) {
                ans[i] = ans[j]+1;
                memoi[i] = j;
            }
        }
        if(ans[i] > ansSize){
            ansSize = ans[i];
            ansInx = i;
        }
    }

    //출력부
    vector<int> pt;
    int tmp = ansInx;
    while(tmp != -1){
        pt.push_back(v[tmp]);
        tmp = memoi[tmp];
    }
    cout << ansSize << endl;
    for(int i = pt.size()-1; i >= 0; i--) cout << pt[i] << " ";
}
