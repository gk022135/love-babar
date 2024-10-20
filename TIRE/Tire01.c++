#include<iostream>

using namespace std;

class TrieNode{
    public:

         char data;
         TrieNode* childern[26];

         bool isTeerminal; 

         TrieNode(char ch){
             data = ch;
             for(int i =0;i<26; i++){
                 childern[i] = NULL;

             }
             isTeerminal = false;
         }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root,string word){
            //base case

            if(word.length() == 0){//matlab last node 

            root->isTeerminal = true;

            }

            //assumption word will be in capital letter
            int index = word[0] - 'A';

            TrieNode* child;

            // if present
            if(root->childern[index] != NULL){
                child = root->childern[index];  // age badh rahe hai

            }
            else{
                // absent hai
                child = new TrieNode(word[0]);
                root ->childern[index] = child;
            }

            // RECURSION
            insertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }



// Search of word in TRIE
        bool searchUtil(TrieNode* root, string word){
            //base case

            if(word.length() == 0){
                return root ->isTeerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root -> childern[index] != NULL){
                child = root->childern[index];
            }
            else{
                //absent
                return false;
            }

            //recursion
            return searchUtil(child,word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root,word);
        }



//removal of child in TRIE
             
  
};
int main(){
    Trie* t =  new Trie();  
    t->insertWord("abcd");

    cout<<"presnt or not"<<t->searchWord("abcd")<<endl;


    return 0; 
}