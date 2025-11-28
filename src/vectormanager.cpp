#include "../include/vectormanager.h"
#include <iostream>

using namespace std;


VectorManager::VectorManager() {
    srand(time(nullptr));
}

void VectorManager::add(int val) {
    data.push_back(val);
}

bool VectorManager::removeValue(int val) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == val) {
            data.erase(it);
            return true;
        }
    }
    return false;
}

void VectorManager::clear() {
    data.clear();
}

void VectorManager::fillRandom(int count, int minVal, int maxVal) {
    data.clear();
    for (int i = 0; i < count; i++) {
        int r = minVal + (rand() % (maxVal - minVal + 1));
        data.push_back(r);
    }
}

void VectorManager::display() const {
    if (data.empty()) {
        cout << "[Vector is empty]" << endl;
        return;
    }

    cout << "[ ";
    for (int v : data) {
        cout << v << " ";
    }
    cout << "]" << endl;
}

vector<int>& VectorManager::getVector() {
    return data;
}
