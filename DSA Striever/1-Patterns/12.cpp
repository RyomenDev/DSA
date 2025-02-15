// https://www.naukri.com/code360/problems/number-crown_6581894

void numberCrown(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1 << " ";
        }
        for (int j = 0; j < n - (i + 1); j++) {
            cout << " ";
        }
        for (int j = i; j >= 0; j--) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}