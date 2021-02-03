#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    int memoi[201][101];

    cin >> N >> M >> K;

    for (int i = 0; i <= N + M; i++) {
        memoi[i][0] = 1;
        memoi[i][i] = 1;
    }

    for (int i = 2; i <= N + M; i++) {
        for (int j = 1; j < i && j <= M; j++) {
            memoi[i][j] = memoi[i - 1][j] + memoi[i - 1][j - 1];
            if (memoi[i][j] > MAX) memoi[i][j] = MAX + 1;
        }
    }

    int n = M + N, m = M;

    if(memoi[n][m] < K){
        cout << "-1";
    } else {
        while (m != 1) {
            if (memoi[n - 1][m] < K) {
                K -= memoi[n - 1][m--];
                cout << 'z';
            } else {
                cout << 'a';
            }
            n--;
        }

        while (n) {
            if (n == K) cout << 'z';
            else cout << 'a';
            n--;
        }
    }
    return 0;
}
