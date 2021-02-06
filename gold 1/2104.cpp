#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N;
vector<ll> arr;

ll dq(int left, int right){
    if(right < left) return 0;
    if(right == left) return arr[left] * arr[right];
    int mid = (left+right)/2,l,r;
    ll tmpMin,tmpSum, tmpAns;
    tmpMin = tmpSum = arr[mid];
    l = r = mid; l--;r++;
    tmpAns = tmpSum * tmpMin;
    while(l >= left || r <= right){
        if(l < left || (r <= right && arr[l] <= arr[r])) {
            if(tmpMin > arr[r]) tmpMin = arr[r];
            tmpSum += arr[r];
            r++;
        }
        else {
            if(tmpMin > arr[l]) tmpMin = arr[l];
            tmpSum += arr[l];
            l--;
        }
        tmpAns = max(tmpAns, tmpSum * tmpMin);
    }

    tmpAns = max(tmpAns, dq(left,mid-1));
    tmpAns = max(tmpAns, dq(mid+1,right));
    return tmpAns;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr.resize(N+1,0);

    for(int i = 1; i <= N; i++) cin >> arr[i];
    ll ans = dq(1,N);
    cout << ans << endl;

    return 0;
}
