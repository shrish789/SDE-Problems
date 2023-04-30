// https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769

int findCelebrity(int n) {
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (knows(ans, i)) {
            ans = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans != i && (knows(ans, i) || !knows(i, ans)))
            return -1;
    }
    return ans;
}
