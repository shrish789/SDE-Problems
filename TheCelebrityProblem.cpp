// https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769

int findCelebrity(int n) {
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (ans == -1) {
            ans = i;
        } else if ((knows(ans, i) && knows(i, ans)) || (!knows(ans, i) && !knows(i, ans))) {
            ans = -1;
        } else if(knows(ans, i)) {
            ans = i;
        }
    }
    if (ans == -1) return ans;
    for (int i = 0; i < n; i++) {
        if (ans != i && (knows(ans, i) || !knows(i, ans)))
            return -1;
    }
    return ans;
}
