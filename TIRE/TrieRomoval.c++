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

    // Helper function to remove a word from the trie
    bool deleteUtil(TrieNode* root, string word) {
        // Base case: If word is empty, mark isTerminal as false
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;

                // Check if the node has no children, meaning we can delete it
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Node has children, so we cannot delete it
                    }
                }

                return true; // Node has no children, so it's safe to delete
            }

            return false; // Word not found
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            return false; // Word not found
        }

        // Recursive call
        bool shouldDeleteChild = deleteUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            // Delete the reference to the child node
            delete child;
            root->children[index] = NULL;

            // Check if current node can be deleted (if it's not terminal and has no children)
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Node has children, so we cannot delete it
                    }
                }

                return true; // Node has no children, so it's safe to delete
            }
        }

        return false;
    }

    // Function to remove a word
    void removeWord(string word) {
        for (int i = 0; i < word.length(); i++) {
            word[i] = toupper(word[i]);
        }
        deleteUtil(root, word);
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

    // Remove word
    t->removeWord("abcd");

    // Search again after removal
    cout << "Present or not (abcd) after removal: " << (t->searchWord("abcd") ? "Yes" : "No") << endl;
    cout << "Present or not (abc) after removal: " << (t->searchWord("abc") ? "Yes" : "No") << endl;

    return 0;
}
