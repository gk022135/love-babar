#include<iostream>
#include<vector>

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
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true; // mark as terminal node
            return;
        }

        // Assumption: word will be in lowercase letters
        int index = word[0] - 'a';

        TrieNode* child;

        // If the character is already present
        if (root->children[index] != NULL) {
            child = root->children[index]; // move forward
        } else {
            // Character not present, so create a new node
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
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // If character is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // Character not present
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // Longest common prefix function
    string longestCommonPrefix(vector<string>& words) {
        // Insert all words into the Trie
        for (string word : words) {
            insertWord(word);
        }

        string prefix = "";
        TrieNode* current = root;

        // Traverse the Trie to find the longest common prefix
        while (true) {
            int countChildren = 0;
            TrieNode* nextNode = nullptr;

            // Check how many children this node has
            for (int i = 0; i < 26; i++) {
                if (current->children[i] != NULL) {
                    countChildren++;
                    nextNode = current->children[i];
                }
            }

            // If there's more than 1 child or we've reached a terminal node, break
            if (countChildren != 1 || current->isTerminal) {
                break;
            }

            // Move to the next node
            current = nextNode;
            prefix += current->data;
        }

        return prefix;
    }
};

int main() {
    Trie* t = new Trie();
    vector<string> words = {"flower", "flow", "flight"};
    
    string prefix = t->longestCommonPrefix(words);
    cout << "Longest common prefix: " << prefix << endl;

    return 0;
}
