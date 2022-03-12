// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while (!st.empty() && st.top().first <= price) {
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};
