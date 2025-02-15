// https://www.naukri.com/code360/problems/increasing-number-triangle_6581893

void nNumberTriangle(int n) {
    // Write your code here.
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << cnt << " ";
            cnt++;
        }
        cout << endl;
    }
}