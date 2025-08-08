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

        int idx = word[0] - 'a';
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

        int idx = word[0] - 'a';
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

        int idx = word[0] - 'a';
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

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if(curr->isTerminal) {
            temp.push_back(prefix);
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if(next != NULL) {
                prefix += ch;
                printSuggestions(next, temp, prefix);
                prefix.pop_back(); //backtracking step
            }
        }
    }

    vector<vector<string>> getSuggestions(string& s) {
        TrieNode* prev = root;
        vector<vector<string>> out;
        string prefix = "";
        
        for(int i = 0; i < s.size(); i++) {
            char lastCh = s[i];
            prefix += lastCh;

            //check for lastCh
            TrieNode* curr = prev->children[lastCh - 'a'];

            if(curr == NULL) { //search ended
                while(i < s.size()) {
                    out.push_back({"0"});
                    i++;
                }
                break;
            }
            
            //found
            vector<string>temp;
            printSuggestions(curr, temp, prefix);

            out.push_back(temp);
            temp.clear();
            prev = curr; //move forward
        }
        return out;
    }
};


vector<vector<string>> displayContacts(int n, string contact[], string s) {
    // code here
    Trie t;

    //insert all contact in trie
    for(int i = 0; i < n; i++) {
        t.insertWord(contact[i]);
    }

    //return ans
    return t.getSuggestions(s);
}

int main() {
    return 0;
}