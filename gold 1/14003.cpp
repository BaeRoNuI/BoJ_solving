#include<iostream>
#include<vector>
#define MAX 1000001
using namespace std;

int bs(const int lis[], int target, int size);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int v[MAX], LIS[MAX], memoi[MAX];
    for(int i = 0; i < N; i++) cin >> v[i];

    LIS[0] = v[0];
    memoi[0] = 0;

    int size = 0; // LIS의 마지막 원소 위치 (== LIS의 사이즈 -1)
    for(int i = 1; i < N; i++){
        if(LIS[size] < v[i]){
            LIS[++size] = v[i];
            memoi[i] = size;
        } else {
            int tmp = bs(LIS, v[i],size);
            if(tmp == -2) memoi[i] = -3;// 중복된 수가 있을때 후위에 있는 수는 메리트가 없음
            else {
                LIS[tmp] = v[i];
                memoi[i] = tmp;
            }
        }
    }

    //출력부
    cout << size+1 << endl;
    vector<int> ans(size+1);
    for(int i = N-1; i>= 0; i--){
        if(memoi[i] == size){
            ans[size--] = v[i];
        }
    }
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}

int bs(const int lis[], int target, int size){
    int left = 0, right = size, mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(lis[mid] == target) return -2;
        else if(lis[mid] > target) right = mid-1;
        else left = mid+1;
    }
    if(lis[mid] < target) mid++;
    return mid;
}
