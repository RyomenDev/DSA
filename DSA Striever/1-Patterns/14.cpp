// https://www.naukri.com/code360/problems/increasing-letter-triangle_6581897/

void nLetterTriangle(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        char start = 'A';
        for (int j = 0; j < i + 1; j++) {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
}