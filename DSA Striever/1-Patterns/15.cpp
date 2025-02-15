// https://www.naukri.com/code360/problems/reverse-letter-triangle_6581906

void nLetterTriangle(int n) {
    // Write your code here.
    for (int i = n; i > 0; i--) {
        char start = 'A';
        for (int j = 0; j < i; j++) {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
}