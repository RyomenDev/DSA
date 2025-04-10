// Word Ladder I
// https://www.geeksforgeeks.org/problems/word-ladder/1
// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        if (st.find(targetWord) == st.end()) return 0;

        queue<pair<string, int>>q;
        q.push({startWord,1});
        st.erase(startWord);

        while (!q.empty()) {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (temp == targetWord) return len + 1;
                    if (st.find(temp) != st.end()) {
                        q.push({temp, len + 1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};