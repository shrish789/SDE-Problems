// https://www.interviewbit.com/problems/allocate-books/

int isAllocationPossible(int maxPages, int B, vector <int> &A) {
    int res = 0, pages = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > maxPages) return false;
        if (pages + A[i] > maxPages) {
            pages = A[i];
            res++;
        } else {
            pages += A[i];
        }
    }
    if (res < B) {
        return true;
    }
    return false;
}

int Solution::books(vector<int> &A, int B) {
    int low = 1, high = 1e9, mid;
    if (B > A.size()) return -1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (isAllocationPossible(mid, B, A)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
