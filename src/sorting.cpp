#include "../include/sorting.h"
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

static void merge(std::vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = a[l + i];
    for (int j = 0; j < n2; ++j) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++]; else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void bubbleSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j+1]) { std::swap(a[j], a[j+1]); swapped = true; }
        }
        if (!swapped) break;
    }
}

void insertionSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) { a[j+1] = a[j]; --j; }
        a[j+1] = key;
    }
}

void mergeSort(std::vector<int>& a) {
    std::function<void(int,int)> ms = [&](int l, int r){
        if (l >= r) return;
        int m = l + (r - l) / 2;
        ms(l, m);
        ms(m+1, r);
        merge(a, l, m, r);
    };
    if (!a.empty()) ms(0, (int)a.size() - 1);
}

static int partition(std::vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] < pivot) { ++i; std::swap(a[i], a[j]); }
    }
    std::swap(a[i+1], a[high]);
    return i+1;
}

void quickSort(std::vector<int>& a) {
    std::function<void(int,int)> qs = [&](int low, int high){
        if (low < high) {
            int pi = partition(a, low, high);
            qs(low, pi - 1);
            qs(pi + 1, high);
        }
    };
    if (!a.empty()) qs(0, (int)a.size() - 1);
}
