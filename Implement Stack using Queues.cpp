// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int n;
    MyStack() {
        n=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        n++;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp,i=1;
        while(1){
            temp=q.front();
            q.pop();
            if(i++==n) break;
            q.push(temp);
        }
        n--;
        return temp;
    }
    
    /** Get the top element. */
    int top() {
       int temp,i=1;
        while(1){
            temp=q.front();
            q.pop();
            q.push(temp);
            if(i++==n) break;
        }
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
