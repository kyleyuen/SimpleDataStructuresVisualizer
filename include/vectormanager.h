#ifndef VECTORMANAGER_H
#define VECTORMANAGER_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

class VectorManager {
private:
    std::vector<int> data;

public:
    VectorManager();

    void add(int val);
    bool removeValue(int val);
    void clear();
    void fillRandom(int count, int minVal = 0, int maxVal = 100);
    
    void display() const;

    std::vector<int>& getVector();
};

#endif
