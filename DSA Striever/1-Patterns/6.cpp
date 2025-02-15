// https://www.naukri.com/code360/problems/reverse-number-triangle_6581889

void nNumberTriangle(int n) {
    // Write your code here.
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}