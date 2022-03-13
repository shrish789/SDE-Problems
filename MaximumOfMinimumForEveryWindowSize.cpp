// https://www.codingninjas.com/codestudio/problems/max-of-min_982935

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    int leftArray[n], rightArray[n];
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        leftArray[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
   	for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        rightArray[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }
    vector<int> res(n, INT_MIN);
    for (int i = 0; i < n; i++) {
        int width = rightArray[i] - leftArray[i] + 1;
//         cout << leftArray[i] << " " << rightArray[i] << " ";
        res[width - 1] = max(res[width - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }
    return res;
}
