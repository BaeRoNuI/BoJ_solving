#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, L, K;
    cin >> N >> M >> L >> K;
    vector<pair<int,int>> vii(K);
    vector<int> posX, posY;
    for(int i = 0; i < K; i++){
        cin >> vii[i].first >> vii[i].second;
        posX.push_back(vii[i].first);
        posY.push_back(vii[i].second);
    }

    int ans = 0;
    for(auto x : posX){
        for(auto y : posY){
            int maxX, maxY, tmp;
            maxX = x + L;
            maxY = y + L;
            tmp = 0;
            for(int j = 0; j < K; j++){
                int tmpX = vii[j].first, tmpY = vii[j].second;
                if(tmpX >= x && tmpX <= maxX && tmpY >= y && tmpY <= maxY) tmp++;
            }
            if(tmp > ans) ans = tmp;
        }
    }
    cout << K - ans << endl;

    return 0;
}
