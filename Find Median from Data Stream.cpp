// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
private:
    multiset <int> st;
    multiset <int> :: iterator low;
    multiset <int> :: iterator high;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (st.size() == 0) {
            st.insert(num);
            low = st.begin();
            high = st.begin();
        } else if (st.size() % 2 == 1) {
            st.insert(num);
            if (num >= *high) {
                high++;
            } else {
                low--;
            }
        } else {
            st.insert(num);
            if (num <= *low) {
                high--;
            } else if (num > *low && num <= *high) {
                low++;
                high--;
            } else {
                low++;
            }
        }
    }
    
    double findMedian() {
        return (*low + *high) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
