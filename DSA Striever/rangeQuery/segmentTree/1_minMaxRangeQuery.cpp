/*
^ given array and some queries(start, end), find the max of given array in the range of query
^ brute force = n^2
^ prefix | suffix = n
^ segment tree - log(n)
*/
/*
! 0 based indexing segment tree
^ Initially there will be a node which keeps the minimum range of [0,n] {inclusive}
^ break equally in two equal parts => 2*idx+1 & 2*idx+2 (if parent node index idx)
^ recursion with base condition
^ segmentTree size -  4n (optimum)
*/

int segmentTree(int idx, int low, int high, vector<int>seq, vector<int>arr) {
    if (low == high) {
        seq[idx] == arr[low];
        return;
    }
    int mid = (low + high) / 2;
    segmentTree(2 * idx + 1, low, mid, seq, arr);
    segmentTree(2 * idx + 2, mid + 1, high, seq, arr);
    seq[idx] = min(seq[2 * mid + 1], seq[2 * idx + 2]);
}


/*
! query
% segment tree [low, high] query[l,r]
^ partial overlap of node with range // % return (leftNode (*) rightNode)  * operation
^ No overlap with range [L,R] // % return INT_MIN || INT_MAX 
    * if(high<l || r<low)
^ complete overlap with (L,R) // % return seq[idx]
    * if(low>=l && high<=r) // % segment tree in b/w
*/