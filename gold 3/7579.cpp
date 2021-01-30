#include<iostream>
#include<vector>
using namespace std;

/* 6:07 시작
 * 7:10 끝..
 * 직관성 있게 변수 이름 잘 정하자..
 */

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    int maxMemory = -M, totalCost = 0;
    vector<int> memory(N), cost(N);
    for(int i = 0; i < N; i++){
        cin >> memory[i]; maxMemory += memory[i];
    }
    for(int i = 0; i < N; i++){
        cin >> cost[i]; totalCost += cost[i];
    }

    vector<int> memorySum(10001,0);
    for(int i = 0; i < N; i++){
        if(cost[i] == 0){
            continue;
        }
        for(int j = 10000 - cost[i]; j > 0; j--){
            if(memorySum[j] > 0){
                if(!memorySum[j+cost[i]] || (memorySum[j+cost[i]] && memorySum[j + cost[i]] > memorySum[j] + memory[i]))
                    memorySum[j + cost[i]] = memorySum[j] + memory[i];
            }
        }
        if(memorySum[cost[i]] == 0 || memorySum[cost[i]] > memory[i]) memorySum[cost[i]] = memory[i];
    }

    int ans = 0;
    for(int i = 10000 ; i >= 0; i--){
        if(memorySum[i] && memorySum[i] <= maxMemory){
            ans = i; break;
        }
    }
    cout << totalCost - ans << endl;

    return 0;
}
