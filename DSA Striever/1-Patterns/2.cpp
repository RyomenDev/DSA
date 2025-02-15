// https://www.naukri.com/code360/problems/n-2-forest_6570178

void nForest(int n) {
    // Write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
