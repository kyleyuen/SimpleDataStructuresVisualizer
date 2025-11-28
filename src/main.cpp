#include "../include/linkedlist.h"
#include "../include/doublylinkedlist.h"
#include "../include/vectormanager.h"
#include "../include/sorting.h"

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

static void section(const string &title) {
    cout << "\n===== " << title << " =====" << endl;
}

template<typename F>
long long timeit(F fn, vector<int> data){
    auto start = chrono::high_resolution_clock::now();
    fn(data);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main() {
    // Singly-linked list demo
    Linkedlist s;
    section("Singly Linked List Demo");

    cout << "Insert head 5" << endl; s.insertHead(5); s.display();
    cout << "Insert head 3" << endl; s.insertHead(3); s.display();
    cout << "Insert tail 9" << endl; s.insertTail(9); s.display();

    cout << "Search for 5 -> position: " << s.search(5) << endl;

    cout << "Delete value 3" << endl;
    if (s.deleteValue(3)) cout << "Deleted 3" << endl; else cout << "3 not found" << endl;
    s.display();

    cout << "Complexities (Singly Linked List):" << endl;
    cout << "  Access: O(n) | Search: O(n) | Insert head: O(1) | Insert tail: O(n) | Delete: O(n)" << endl;

    cout << "Delete value 42 (not present)" << endl;
    if (!s.deleteValue(42)) cout << "42 not found (as expected)" << endl;
    s.display();

    // Doubly-linked list demo
    DoublyLinkedList d;
    section("Doubly Linked List Demo");

    cout << "Insert head 5" << endl; 
    d.insertHead(5); 
    d.displayForward();

    cout << "Insert head 3" << endl; 
    d.insertHead(3);
    d.displayForward();

    cout << "Insert tail 10" << endl; 
    d.insertTail(10); 
    d.displayForward();

    cout << "Insert tail 12" << endl; 
    d.insertTail(12); 
    d.displayForward();

    cout << "Display backward (tail -> head):" << endl; 
    d.displayBackward();

    cout << "Delete value 10" << endl;
    if (d.deleteValue(10)) cout << "Deleted 10" << endl; 
    else cout << "10 not found" << endl;
    d.displayForward();

    cout << "Search for 5 -> position: " << d.search(5) << endl;

    cout << "Complexities (Doubly Linked List):" << endl;
    cout << "  Access: O(n) | Search: O(n) | Insert head/tail: O(1) | Delete: O(1) if node known, O(n) if searched" << endl;

    section("Sorting Algorithms Demo");

    auto printPreview = [](const vector<int>& v, int preview=10){
        cout << "[ ";
        for (int i = 0; i < (int)min((size_t)preview, v.size()); ++i) cout << v[i] << " ";
        if ((int)v.size() > preview) cout << "... ";
        cout << "] (n=" << v.size() << ")" << endl;
    };

    // generate data
    vector<int> bigForSlow; // for bubble/insertion
    vector<int> bigForFast; // for merge/quick
    int nSlow = 2000; // bubble/insertion
    int nFast = 200000; // merge/quick
    bigForSlow.reserve(nSlow);
    bigForFast.reserve(nFast);
    for (int i = 0; i < nSlow; ++i) bigForSlow.push_back(rand() % nSlow);
    for (int i = 0; i < nFast; ++i) bigForFast.push_back(rand() % nFast);

    cout << "Bubble Sort on n=" << nSlow << ": ";
    auto bdata = bigForSlow; // copy
    auto t_bubble = timeit([](vector<int>& d){ bubbleSort(d); }, bdata);
    cout << t_bubble << " ms" << endl;
    printPreview(bdata);

    cout << "Insertion Sort on n=" << nSlow << ": ";
    auto idata = bigForSlow;
    auto t_insert = timeit([](vector<int>& d){ insertionSort(d); }, idata);
    cout << t_insert << " ms" << endl;
    printPreview(idata);

    cout << "Merge Sort on n=" << nFast << ": ";
    auto mdata = bigForFast;
    auto t_merge = timeit([](vector<int>& d){ mergeSort(d); }, mdata);
    cout << t_merge << " ms" << endl;
    printPreview(mdata);

    cout << "Quick Sort on n=" << nFast << ": ";
    auto qdata = bigForFast;
    auto t_quick = timeit([](vector<int>& d){ quickSort(d); }, qdata);
    cout << t_quick << " ms" << endl;
    printPreview(qdata);

    cout << "Runtimes (Sorting):" << endl;
    cout << "  Bubble: O(n^2) | Insertion: O(n^2) | Merge: O(n log n) | Quick: O(n log n) average, O(n^2) worst" << endl;

    // VectorManager demo
    section("Vector Manager Demo");
    cout << "Complexities (VectorManager - std::vector):" << endl;
    cout << "  Access: O(1) | Search: O(n) | Insert back: amortized O(1) | Remove: O(n) | Clear: O(n)" << endl;
    
    // Linear search demo (vector)
    section("Search Demo");
    vector<int> svec = {5, 3, 8, 1, 9, 4};
    cout << "Linear search in vector for 9 -> ";
    auto lin_pos = -1;
    for (size_t i = 0; i < svec.size(); ++i) if (svec[i] == 9) { lin_pos = (int)i+1; break; }
    if (lin_pos != -1) cout << "position " << lin_pos << endl; else cout << "not found" << endl;

    // Linear search in linked list
    Linkedlist ls;
    for (int v : svec) ls.insertTail(v);
    cout << "Linear search in linked list for 1 -> position " << ls.search(1) << endl;

    // Binary search (vector only) - requires sorted vector
    auto bsearchVec = svec; sort(bsearchVec.begin(), bsearchVec.end());
    cout << "Binary search for 4 in sorted vector: ";
    bool found = binary_search(bsearchVec.begin(), bsearchVec.end(), 4);
    cout << (found ? "found" : "not found") << endl;

    cout << "Complexities (Search):" << endl;
    cout << "  Linear search (vector or linked list): O(n)" << endl;
    cout << "  Binary search (vector only, requires sorted): O(log n)" << endl;

    VectorManager vm;
    cout << "Fill random 5 values (0..20)" << endl;
    vm.fillRandom(5, 0, 20);
    vm.display();

    cout << "Add value 42" << endl;
    vm.add(42);
    vm.display();

    cout << "Remove value 42" << endl;
    if (vm.removeValue(42)) cout << "Removed 42" << endl; else cout << "42 not found" << endl;
    vm.display();

    cout << "Clear vector" << endl;
    vm.clear();
    vm.display();

    section("End of demo");
    return 0;
}
