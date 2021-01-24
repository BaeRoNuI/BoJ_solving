#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> v(N), inc(N,1), dec(N,1);

    for(int i = 0; i < N; i++){
        cin >> v[i];
        for(int j = 0; j < i; j++) {
            if (v[i] > v[j]) inc[i] = max(inc[i], inc[j] + 1);
        }
    }

    for(int i = N-1; i >=0; i--){
        for(int j = N-1; j > i; j--){
            if (v[i] > v[j]) dec[i] = max(dec[i], dec[j] + 1);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(inc[i]+dec[i]-1,ans);

    cout << ans << endl;
    return 0;
}
