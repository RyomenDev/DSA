// https://www.naukri.com/code360/problems/alpha-ramp_6581888

void alphaRamp(int n) {
    // Write your code here.
    char start = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << start << " ";
        }
        cout << endl;
        start++;
    }
}
