#include <bits/stdc++.h> 
// https://www.codingninjas.com/codestudio/problems/2099908

class Queue {
private:
    vector <int> v;
    int firstPos = 0;
public:
    Queue() {
        // Implement the Constructor
    }

    bool isEmpty() {
        if (firstPos == v.size()) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        v.push_back(data);
    }

    int dequeue() {
        if (firstPos != v.size()) {
            firstPos++;
            return v[firstPos - 1];
        }
        return -1;
    }

    int front() {
        if (firstPos != v.size()) {
            return v[firstPos];
        }
        return -1;
    }
};
