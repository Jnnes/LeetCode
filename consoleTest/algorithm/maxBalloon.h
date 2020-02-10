#pragma once
#include "../BaseSolution.h"
#include "../Common.h"

int maxNumberOfBalloons(string text) {
    std::map<char, int> mapc;
    mapc['b'] = 0;
    mapc['a'] = 0;
    mapc['l'] = 0;
    mapc['o'] = 0;
    mapc['n'] = 0;
    for (int i = 0; i < text.length(); i++) {
        auto tempc = text[i];
        if (mapc.find(tempc) != mapc.cend()) {
            mapc[tempc] = mapc[tempc] + 1;
        }
    }

    int ret = INT_MAX;
    for (auto iter = mapc.begin(); iter != mapc.cend(); iter++) {
        char tempc = iter->first;
        int count = iter->second;
        if (tempc == 'l' || tempc == 'o') {
            ret = count / 2 < ret ? count / 2 : ret;
        }
        else {
            ret = count < ret ? count : ret;
        }
    }

    return ret;
}

class MaxBalloon :public BaseSolution
{
public:    
    void init(void);
    void run(void);
    void result(void);    
};

void MaxBalloon::init() {
}

void MaxBalloon::run() {
    cout << "½á¹ûÎª£º"<< maxNumberOfBalloons("lloo")<<endl;
}

void MaxBalloon::result() {
}