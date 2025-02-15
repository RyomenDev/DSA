// https://www.naukri.com/code360/problems/ninja-and-the-star-pattern-i_6581920

void getStarPattern(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            for (int j = 0; j < n; j++) {
                cout << "*";
            }
        }
        else {
            cout << "*";
            for (int j = 0; j < n - 2; j++) {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}
