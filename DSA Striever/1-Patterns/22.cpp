// https://www.naukri.com/code360/problems/ninja-and-the-number-pattern-i_6581959

void getNumberPattern(int n) {
    // Write your code here.
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int curr = n - min({i,2 * n - 1 - i - 1,j,2 * n - 1 - j - 1});
            cout << curr;
        }
        cout << endl;
    }
}