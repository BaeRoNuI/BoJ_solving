#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    int N;
    cin >> N;
    vector<int> v(N), ans(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i = N-1; i >= 0; i--){
        while(!s.empty()){
            if(v[i] >= s.top()) s.pop();
            else break;
        }
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    for(auto i : ans){
        cout << i << " ";
    } cout << endl;

    return 0;
}
