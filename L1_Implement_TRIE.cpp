#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = 0;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void putChar(char ch, Node *node){
        links[ch-'a'] = node;
    }

    Node *getChar(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = 1;
    }

    bool isEnd(){
        return flag;
    }
};


class Trie {
private:
    Node *root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->putChar(word[i], new Node);
            }
            node = node->getChar(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->getChar(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i]))
                return 0;
            node = node->getChar(prefix[i]);
        }
        return 1;
    }
};