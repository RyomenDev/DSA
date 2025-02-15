// https://www.naukri.com/code360/problems/implement-trie_631356

#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // root node with null character
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
            child = root->children[index];
        else { // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
            child = root->children[index];
        else // Absent
            return false;

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;
            }
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            // Word doesn't exist
            return;
        }

        // Recursion
        removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};

void Vatsh() {
    Trie* t = new Trie;

    t->insertWord("ABCD");
    cout << "Present | Not: " << t->searchWord("ABCD") << endl;

    t->insertWord("XYZ");
    cout << "Present | Not: " << t->searchWord("XYZ") << endl;

    t->removeWord("ABCD");
    cout << "Present | Not after removal: " << t->searchWord("ABCD") << endl;

}

int32_t main() {
    Vatsh();
    return 0;
}



/*

    // Your Trie object will be instantiated and called as such:
    // Trie* obj = new Trie();
    // obj->insert(word);
    // bool check2 = obj->search(word);
    // bool check3 = obj->startsWith(prefix);


class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

public:
    TrieNode* root;
    //  Initialize your data structure here.
    Trie() { root = new TrieNode('\0'); }

    void insertUtil(TrieNode* root, string word) {
      // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
            child = root->children[index];
        else { // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    //  Inserts a word into the trie.
    void insert(string word) { insertUtil(root, word); }

    bool searchUtil(TrieNode* root, string word) {
      // base case
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
            child = root->children[index];
        else // Absent
            return false;

          // Recursion
        return searchUtil(child, word.substr(1));
    }
    //  Returns if the word is in the trie.
    bool search(string word) { return searchUtil(root, word); }

    bool startsWithUtil(TrieNode* root, string word) {
      // base case
        if (word.length() == 0)
            return true;

        int index = word[0] - 'a';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
            child = root->children[index];
        else // Absent
            return false;

          // Recursion
        return startsWithUtil(child, word.substr(1));
    }

    // Returns if there is any word in the trie that starts with the given
    // prefix.
    bool startsWith(string prefix) { return startsWithUtil(root, prefix); }
};
*/