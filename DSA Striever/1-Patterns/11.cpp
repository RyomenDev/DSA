// https://www.naukri.com/code360/problems/binary-number-triangle_6581890

void nBinaryTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        int start = (i & 1) ? 0 : 1;
        for (int j = 0; j < i + 1; j++) {
            cout << start << " ";
            start = !start;
        }
        cout << endl;
    }
}