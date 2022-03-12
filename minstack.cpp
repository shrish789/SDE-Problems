/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

*/

// FIRST APPROACH: Using two stacks
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st,st1;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(st1.empty()) st1.push(x);
        else if(st1.top()>=x) st1.push(x);
    }
    
    void pop() {
        if(!st1.empty() && st.top()==st1.top()) st1.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st1.top();
    }
};

// SECOND APPROACH: Same as first one but easier
class MinStack {
public:
    stack < pair < int, int >> st;
    MinStack() {
        
    }
    
    void push(int val) {
        int minElement = st.empty() ? val : min(val, st.top().second);
        st.push({val, minElement});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


// THIRD APPROACH: Using single stack and no pair
class MinStack {
public:
    stack < long long > st;
  long long mini;
  public:
    /** initialize your data structure here. */
    MinStack() {
      while (st.empty() == false) st.pop();
      mini = INT_MAX;
    }

  void push(int value) {
    long long val = (long long)value;
    if (st.empty()) {
      mini = val;
      st.push(val);
    } else {
      if (val < mini) {
        st.push(2 * val - mini);
        mini = val;
      } else {
        st.push(val);
      }
    }
  }

  void pop() {
    long long el = st.top();
    st.pop();
    if (el < mini) {
      mini = 2 * mini - el;
    }
  }

  int top() {
    long long el = st.top();
    if (el < mini) return mini;
    return el;
  }

  int getMin() {
    return mini;
  }

};
