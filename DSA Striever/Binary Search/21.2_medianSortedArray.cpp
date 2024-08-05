// https://www.interviewbit.com/problems/median-of-array/

double solve(const vector<int>& A, const vector<int>& B) {
    int n1 = A.size(), n2 = B.size();
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = (mid1 > 0) ? A[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? B[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? A[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? B[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1)
                return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }
    return 0;
}

double Solution::findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    int n1 = A.size(), n2 = B.size();

    // Handle trivial cases where one array is empty
    if (n1 == 0)
        return (n2 % 2 == 0) ? (B[n2 / 2 - 1] + B[n2 / 2]) / 2.0 : B[n2 / 2];
    if (n2 == 0)
        return (n1 % 2 == 0) ? (A[n1 / 2 - 1] + A[n1 / 2]) / 2.0 : A[n1 / 2];

    // Ensure that A is the smaller array
    if (n1 > n2)
        return findMedianSortedArrays(B, A);
    return solve(A, B);
}
