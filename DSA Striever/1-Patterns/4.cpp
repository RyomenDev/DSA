// https://www.naukri.com/code360/problems/triangle_6573690

void triangle(int n) {
    // Write your code here
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}