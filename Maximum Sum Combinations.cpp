// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector <int> res;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    set <pair <int, pair <int, int>>> st;
    st.insert(make_pair(A[n - 1] + B[n - 1], make_pair(n - 1, n - 1)));
    int i, j;
    while (res.size() < C) {
        auto it = st.end();
        it--;
        res.push_back((*it).first);
        i = (*it).second.first, j = (*it).second.second;
        if (i > 0)
            st.insert(make_pair(A[i - 1] + B[j], make_pair(i - 1, j)));
        if (j > 0)
            st.insert(make_pair(A[i] + B[j - 1], make_pair(i, j - 1)));
        st.erase(it);
    }
    return res;
}
