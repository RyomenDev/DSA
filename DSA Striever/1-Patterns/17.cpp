// https://www.naukri.com/code360/problems/alpha-hill_6581921

void alphaHill(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        char start = 'A';
        for (int j = 0; j < n - (i + 1); j++) {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++) {
            cout << start << " ";
            start++;
        }
        start--;
        for (int j = 0; j < i; j++) {
            start--;
            cout << start << " ";
        }
        for (int j = 0; j < n - (i + 1); j++) {
            cout << " ";
        }
        cout << endl;
    }
}