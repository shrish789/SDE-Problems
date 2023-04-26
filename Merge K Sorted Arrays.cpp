// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379

include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k) {
    set <pair <int, pair <int, int>>> st;
    vector <int> res;
    for (int i = 0; i < kArrays.size(); i++) {
        st.insert(make_pair(kArrays[i][0], make_pair(i, 0)));
    }

    while (!st.empty()) {
        auto it = st.begin();
        res.push_back((*it).first);
        int i = (*it).second.first, j = (*it).second.second;
        if (kArrays[i].size() > j + 1) {
            st.insert(make_pair(kArrays[i][j + 1], make_pair(i, j + 1)));
        }
        st.erase(it);
    }
    return res;
}
