#include <iostream>
#include <vector>
#include <string>
#define UNVISITED 999999999
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int size = s.size();

    vector<vector<bool>> memoi(size+1,vector<bool>(size+1,false));

    for(int i = 0; i < size; i++){
        memoi[i][i] = 1;
        if(i < size-1 && s[i] == s[i+1]) {
            memoi[i][i + 1] = 1;
        }
    }
    for(int i = 1; i < size-1; i++){
        for (int j = 1; (j + i < size) && (i >= j); j++){
            if (s[i-j] == s[i+j] && memoi[i - j + 1][i + j - 1]) {
                memoi[i - j][i + j] = true;
            }
            if(i+j+1 < size && s[i-j] == s[i+j+1] && memoi[i - j + 1][i + j]){
                memoi[i - j][i + j + 1] = true;
            }
        }
    }

    vector<int> dist(size+1,UNVISITED); dist[0] = 0;
    for(int i = 1; i <= size; i++){
        int tmp = UNVISITED;
        for(int j = 1; j <= i; j++){
            if(memoi[j-1][i-1]) tmp = min(tmp,dist[j-1]+1);
        }
        dist[i] = tmp;
    }
    cout << dist[size] << endl;

    return 0;
}
