// https://leetcode.com/problems/implement-queue-using-stacks/description/


// Approach #1 (Two Stacks) Push - O(n) per operation, Pop - O(1) per operation.
class MyQueue {
private:
    stack <int> st1, st2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int ele = st1.top();
        st1.pop();
        return ele;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        if (st1.size()) {
            return false;
        }
        return true;
    }
};

// Approach #2 (Two Stacks) Push - O(1) per operation, Pop - Amortized O(1) per operation.
class MyQueue {
private:
    stack <int> st1, st2;
    int front;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (st1.empty()) {
            front = x;
        }
        st1.push(x);
    }
    
    int pop() {
        if (st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ele = st2.top();
        st2.pop();
        return ele;
    }
    
    int peek() {
        if (!st2.empty()) {
            return st2.top();
        }
        return front;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};
