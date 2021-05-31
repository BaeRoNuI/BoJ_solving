#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#include <map>
#include <fstream>
#include <sstream>

#include "process.h"
#include "utils.cpp"

using namespace std;

vector<queue<string>> MSQ(10); // Multi-level-queue
vector<pair<pair<int,int>, string>> op; // a clock-cycle에 b priority를 갖는 c를 수행
map<string, vector<pair<int,int>>> process; // process의 정보를 갖고있고, 각각 process가 수행하는 작업 저장
map<string, int>    priority;
const int kMaxTime = 10; //max timequantum : 10
string f_input, f_scheduler, f_memory;
int pageAlgo;

void init_algo(int argc, char** argv);

int main(int argc, char** argv)
{
    init_algo(argc, argv);

    int numEvent, sizeVM, sizePM, sizePF;
    int tq = 0, curPriority = 10, curSeq = 0;
    string cur = "";

    vector<string> data_inp = f_get(f_input, "input");
    numEvent = stoi(data_inp[0]); sizeVM = stoi(data_inp[1]); sizePM = stoi(data_inp[2]); sizePF = stoi(data_inp[3]);

    for(int i = 4; i < data_inp.size(); i += 3){
        op.push_back({{stoi(data_inp[i]), stoi(data_inp[i+2])},data_inp[i+1]});
        if (data_inp[i+1] != "INPUT")
            priority.insert({data_inp[i+1], stoi(data_inp[i+2])});
    }
    for(auto & i : op) {
        if (i.second == "INPUT") continue;
        string tmp = i.second + ".txt";
        data_inp = f_get(f_input, tmp);
        int num = stoi(data_inp[0]);
        vector<pair<int,int>> tmpP;
        for(int j = 0; j < num; j+=2) {
            tmpP.emplace_back(stoi(data_inp[j + 1]) ,stoi(data_inp[j + 2]));
        }
        process.insert({i.second,tmpP});
    }

    int time = 0;
    while(numEvent) {
        if (curSeq < op.size() && op[curSeq].first.first == time) {
            if(op[curSeq].second == "INPUT") {

            } else
                MSQ[op[curSeq].first.second].push(op[curSeq].second);
            curSeq++;
        }
        // 새로운 Process를 찾아야할 때, priority순으로 MSQ를 돌아봄
        for(int i = 0; i < curPriority; i++) {
            if (MSQ[i].empty()) continue;
            cur = MSQ[i].front();
            curPriority = priority[cur];
            break;
        }

        if (cur == "")
            break;
        // do something


        if (tq == 9) {
            tq = 0;
        } else {
            if (curPriority < 5) tq = 0;
            tq++;
        }
    }

    return 0;
}

void init_algo(int argc, char** argv) {
    string algo[3] = {"-page=lru", "-page=sampled", "-page=clock"};
    string dir_q = "-dir=";
    string dir = "./";

    pageAlgo = 0;
    for (int i = 1; i < argc; i++) {
        string tmpS = string(argv[i]);
        transform(tmpS.begin(), tmpS.end(), tmpS.begin(), ::tolower);
        if (tmpS == algo[0])
            pageAlgo = 0;
        else if (argv[i] == algo[1])
            pageAlgo = 1;
        else if (argv[i] == algo[2])
            pageAlgo = 2;
        else {
            int pos = 1;
            for(int j = 0; j < 5; j++) {
                if(argv[i][j] != dir_q[j])
                    pos = 0;
            }
            if (pos) {
                int j = 5;
                while(argv[i][j])
                    dir.push_back(argv[i][j++]);
            }
        }
    }

    f_input = dir + "input/";
    f_scheduler = dir + "scheduler.txt";
    f_memory = dir + "memory.txt";
}



