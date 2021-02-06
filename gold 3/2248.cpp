#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<vector<ll>> memoi(32,vector<ll>(32,0));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, L, I;
    cin >> N >> L >> I;

    for(int i = 0; i < 32; i++){
        memoi[i][0] = memoi[i][i] = 1;
        if(i > 1){
            for(int j = 1; j < i; j++){
                memoi[i][j] = memoi[i-1][j-1] + memoi[i-1][j];
            }
        }
    }

    for(int i = N; i > 0; i--){
        ll tmp = 0;
        for(int j = 0; j <= L && j < i; j++) tmp += memoi[i-1][j];
        if(I > tmp && L > 0) {
            cout << 1; L--;
            I -= tmp;
        } else if(I == 2 && i == 1 && L > 0) {
            cout << 1; I = 0; L--;
        } else  {
            cout << 0;
        }
    }

    return 0;
}
