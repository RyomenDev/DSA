// https://www.naukri.com/code360/problems/alpha-triangle_6581429

void alphaTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        char start = 'A' + n - 1;
        for (int j = 0; j < i + 1; j++) {
            cout << start << " ";
            start--;
        }
        cout << endl;
    }
}