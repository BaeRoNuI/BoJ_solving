#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        ll a, b, ans;
        cin >> a >> b;
        while(a != 0){
            ans = b/a;
            if(b%a) ans++;
            a = a * ans - b;
            b = b * ans;
        }
        cout << ans << endl;
    }
    return 0;
}
