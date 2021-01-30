#include<iostream>
#include<vector>
using namespace std;

/* 5:43분 시작
 * 6:05분 정답 // 22분 소요
 * 냅색 알고리즘(가방 알고리즘)
 */

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int N; cin >> N;
    vector<bool> pos(40001,0);
    vector<int> num(N);
    pos[0] = true;

    for(int i = 0; i < N; i++){
        cin >> num[i];
        for(int j = 40000; j >= 0; j--){
            if(pos[j] && num[i] + j < 40001){
                pos[num[i]+j] = true;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 40001; j++){
            if(pos[j] && j - num[i] > 0){
                pos[j-num[i]] = true;
            }
        }
    }


    cin >> N;
    int tmp;
    while(N--){
        cin >> tmp;
        if(pos[tmp]) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}


