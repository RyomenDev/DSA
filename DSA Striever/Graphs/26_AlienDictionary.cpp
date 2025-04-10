
// Alien Dictionary
// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
public:
    string findOrder(vector<string>& words) {
        vector<vector<int>>graph(26);
        vector<int> inDegree(26, 0), isPresent(26, 0);

        for (const auto& word : words)
            for (char c : word)
                isPresent[c - 'a'] = 1;

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j] - 'a'].push_back(w2[j] - 'a');
                    // inDegree[w2[j] - 'a']++;
                    found = true;
                    break;
                }
            }
            // If no differing character and w1 is longer, invalid order
            if (!found && w1.size() > w2.size())
                return "";
        }

        for (auto i : graph) {
            for (auto j : i) {
                inDegree[j]++;
            }
        }
        queue<int>q;
        for (int i = 0; i < 26; i++)
            if (!inDegree[i] && isPresent[i])
                q.push(i);

        string ans = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans += (char)(curr + 'a');
            for (auto i : graph[curr]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    q.push(i);
            }
        }

        // Check if topological sort included all present characters
        int totalChars = count(isPresent.begin(), isPresent.end(), 1);
        if (ans.size() != totalChars)
            return "";
        return ans;
    }
};