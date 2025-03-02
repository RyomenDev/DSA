// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
    bool isPalindrome(string s) {
        cout << s << " ";
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }
    bool solve(int start, vector<string>& tmp, string& s) {
        int n = s.length();
        if (start == 0)
            return true;
        for (int end = n - 1; end >= start; end--) {
            if (isPalindrome(s.substr(start, end - start + 1))) {
                tmp.push_back(s.substr(start, end - start + 1));
                if (solve(end - 1, tmp, s))
                    return true;
                tmp.pop_back();
            }
        }
        return false;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        solve(0, tmp, s);
        return {};
    }
};