#include<bits/stdc++.h>
using namespace std;

//Approach 1
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 1) return strs[0];

    string ans = "";
    //for traversing all char
    for(int i = 0; i < strs[0].size(); i++) {
        char ch = strs[0][i];

        bool matched = true;
        //checking with other strings corresponding char
        for(int j = 1; j < strs.size(); j++) {
            if(strs[j].size() < i || ch != strs[j][i]) {
                matched = false;
                break;
            }
        }
        if(matched) {
            ans += ch;
        } else {
            break;
        }
    }
    return ans;
}


//Approach 2(Using Trie)
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCnt;
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCnt = 0;
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
        if(word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode* child;

        if(root->children[idx] == NULL) {
            child = new TrieNode(word[0]);
            root->childCnt++;
            root->children[idx] = child;
        } else {
            child = root->children[idx];
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void findLCP(string str, string& ans) {
        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if(root->childCnt == 1) { //move forward
                ans += ch;
                int idx = ch - 'a';
                root = root->children[idx];
            } else break;

            if(root->isTerminal) break;
        }
    }
};

string longestCommonPrefix2(vector<string>& strs) {
    if(strs.size() == 1) return strs[0];
    for(auto str: strs) {
        if(str.size() == 0) return ""; 
    }
    
    Trie t;

    //1. Enter all strings to trie
    for(int i = 0; i < strs.size(); i++) {
        t.insertWord(strs[i]);
    }

    //2.Now for first word traverse the characters and check how many child each character have
    // If one child -> move to next and add the char 
    // If multiple child -> return

    string ans = "";
    string firstStr = strs[0];
    t.findLCP(firstStr, ans);

    return ans;
}


int main() {
    return 0;
}