#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26]; //will map all the characters with the idx
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWordUtil(TrieNode* root, string word) {
        //base case
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        //assumption: word will be in CAPS
        int idx = word[0] - 'A';
        TrieNode* child;

        if(root->children[idx] != NULL) { //present
            //move forward
            child = root->children[idx]; 
        } else { //absent
            //create new node and enter
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        //recrusive call
        insertWordUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertWordUtil(root, word);
    }


    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int idx = word[0] - 'A';
        TrieNode* child;

        if(root->children[idx] != NULL) { //present
            child = root->children[idx];
            
        } else { //absent
            return false;
        }

        //recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }


    void removeUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root->isTerminal = false;
            return;
        }

        int idx = word[0] - 'A';
        TrieNode* child;
        child = root->children[idx];
        removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        if(!searchWord(word)) {
            cout << "Word not exits\n";
            return;
        } 
        removeUtil(root, word);
    }
};

int main() {
    Trie t;
    t.insertWord("ROHAN");
    t.insertWord("TIME");

    if(t.searchWord("TIME")) {
        cout << "Word is present.\n";
    } else {
        cout << "Word is absent.\n";
    }

    t.removeWord("TIME");
    cout << t.searchWord("TIME") << "\n";

    return 0;
}