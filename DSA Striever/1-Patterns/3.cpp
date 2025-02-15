
// https://www.naukri.com/code360/problems/n-triangles_6573689

void nTriangle(int n) {
    // Write your code here
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}