// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
private:
    stack <pair <int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, span));
        return span;
    }
};
