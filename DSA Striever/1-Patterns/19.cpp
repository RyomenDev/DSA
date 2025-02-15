// https://www.naukri.com/code360/problems/symmetric-void_6581919

void symmetry(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}