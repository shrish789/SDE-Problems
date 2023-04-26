// https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209?leftPanelTab=0

#include <bits/stdc++.h> 
class Stack {
private:
    vector <int> v;
    int cap;
public:
    Stack(int capacity) {
        cap = capacity;
    }

    void push(int num) {
        if (v.size() < cap) {
            v.push_back(num);
        }
    }

    int pop() {
        if (v.size() != 0) {
            int lastEle = v.back();
            v.pop_back();
            return lastEle;
        }
        return -1;
    }
    
    int top() {
        if (v.size() != 0) {
            return v.back();
        }
        return -1;
    }
    
    int isEmpty() {
        if (v.size() == 0) {
            return true;
        }
        return false;
    }
    
    int isFull() {
        if (v.size() == cap) {
            return true;
        }
        return false;
    }
    
};
