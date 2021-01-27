#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    int N, ans = 0;
    cin >> N;

    vector<bool> num(N+1,true);
    vector<int> prime;
    num[0] = false; num[1] = false;
    for(ll i = 2; i <= N; i++){
        if(num[i]){
            prime.push_back(i);
            for(ll j = i * i; j <= N; j += i) num[j] = false;
        }
    }

    int left, right, sum;
    sum = left = right = 0;
    while(left <= right && right < prime.size()){
        if(sum < N) sum += prime[right++];
        else if(sum == N){
            ans++; sum += prime[right++];
        } else {
            sum -= prime[left++];
        }
    }
    if(num[N]) ans++;
    cout << ans << endl;

    return 0;
}
