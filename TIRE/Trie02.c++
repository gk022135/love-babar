#include<iostream>
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
        // Base case
        if (word.length() == 0) { // Last node
            root->isTerminal = true;
            return;
        }

        // Assumption: word is in capital letters (for case sensitivity)
        int index = word[0] - 'A'; // If you're using lowercase letters, subtract 'a'

        TrieNode* child;

        // If the character is present
        if (root->children[index] != NULL) {
            child = root->children[index]; // Move to the child node
        } 



        else {
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
            // Convert all characters to uppercase
            word[i] = toupper(word[i]);
        }



        insertUtil(root, word);
    }



    // Helper function to search for a word in the trie
    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A'; // If lowercase, subtract 'a'
        TrieNode* child;

        // If the character is present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        
         else {
            // Character is absent
            return false;
        }

        // Recursion to search the remaining word
        return searchUtil(child, word.substr(1));
    }



    // Function to search for a word
    bool searchWord(string word) {
        for (int i = 0; i < word.length(); i++) {
            // Convert all characters to uppercase
            word[i] = toupper(word[i]);
        }
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    // Insert and search words (converting them to uppercase in the program)
    t->insertWord("abcd");  // This will be converted to "ABCD"
    t->insertWord("Gaurav");
    t->insertWord("kumar");

    // Search the word and print the result
    cout << "Present or not: " << (t->searchWord("abcd") ? "Yes" : "No") << endl; // Converted to "ABCD"
    cout << "Present or not: " << (t->searchWord("Gaurav") ? "Yes" : "No") << endl;

    return 0;
}
