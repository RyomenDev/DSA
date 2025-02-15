// https://www.naukri.com/code360/problems/rotated-triangle_6573688

void nStarTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}