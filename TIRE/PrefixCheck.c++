#include <iostream>
using namespace std;

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
        root = new TrieNode('\0'); // Root node with null character
    }

    // Helper function to insert a word into the trie
    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A'; // If lowercase, subtract 'a'
        TrieNode* child;

        // If the character is present
        if (root->children[index] != NULL) {
            child = root->children[index]; // Move to the child node
        } else {
            // Character is absent, create a new node
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion to insert the remaining word
        insertUtil(child, word.substr(1));
    }

    // Function to insert a word
    void insertWord(string word) {
        for (int i = 0; i < word.length(); i++) {
            word[i] = toupper(word[i]);
        }
        insertUtil(root, word);
    }

    // Helper function to search for a word in the trie
    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    // Function to search for a word
    bool searchWord(string word) {
        for (int i = 0; i < word.length(); i++) {
            word[i] = toupper(word[i]);
        }
        return searchUtil(root, word);
    }

    // Helper function to check if a prefix exists
    bool prefixUtil(TrieNode* root, string prefix) {
        if (prefix.length() == 0) {
            return true; // If you've reached the end of the prefix, it exists
        }

        int index = prefix[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false; // If the character is absent, the prefix doesn't exist
        }

        return prefixUtil(child, prefix.substr(1));
    }

    // Function to check if a prefix exists
    bool searchPrefix(string prefix) {
        for (int i = 0; i < prefix.length(); i++) {
            prefix[i] = toupper(prefix[i]);
        }
        return prefixUtil(root, prefix);
    }
};

int main() {
    Trie* t = new Trie();

    // Insert words
    t->insertWord("abcd");
    t->insertWord("abc");
    t->insertWord("abgl");
    t->insertWord("cdf");
    t->insertWord("lmn");

    // Search words
    cout << "Present or not (abcd): " << (t->searchWord("abcd") ? "Yes" : "No") << endl;
    cout << "Present or not (abc): " << (t->searchWord("abc") ? "Yes" : "No") << endl;

    // Search for prefixes
    cout << "Prefix 'ab' present: " << (t->searchPrefix("ab") ? "Yes" : "No") << endl;
    cout << "Prefix 'abc' present: " << (t->searchPrefix("abc") ? "Yes" : "No") << endl;
    cout << "Prefix 'lm' present: " << (t->searchPrefix("lm") ? "Yes" : "No") << endl;
    cout << "Prefix 'xyz' present: " << (t->searchPrefix("xyz") ? "Yes" : "No") << endl;

    return 0;
}
