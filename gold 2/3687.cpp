#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> memoi(101,0);
int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};


void maximum(int n){
    if(n%2 == 1) {cout << 7; n -= 3;}
    while(n){
        n -=2;
        cout << 1;
    }cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < 9; i++){
        memoi[i] = num[i];
    }
    memoi[6] = 6;
    for(int i = 9; i < 101; i++){
        memoi[i] = memoi[i-2] * 10 + num[2];
        for(int j = 3; j < 8; j++) memoi[i] = min(memoi[i],memoi[i-j] * 10 + num[j]);
    }

    int T;
    cin >> T;

    while(T--){
        int tmp;
        cin >> tmp;
        cout << memoi[tmp] << " ";
        maximum(tmp);
    }

    return 0;
}
