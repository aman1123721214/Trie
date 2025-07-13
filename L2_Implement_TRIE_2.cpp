#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    int startWith = 0, endWith = 0;

    Node* getChar(char ch){
        return links[ch-'a'];
    }

    void putChar(char ch, Node *node){
        links[ch-'a'] = node;
    }

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    void incEndWith(){
        endWith++;
    }

    void incStartWith(){
         startWith++;
    }

    void decEndWith(){
        endWith--;
    }

    void decStartWith(){
        startWith--;
    }
};
class Trie{
private:
    Node *root;

public:
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->putChar(word[i], new Node()); 
            }
            node = node->getChar(word[i]);
            node->incStartWith();
        }
        node->incEndWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i]))
                node = node->getChar(word[i]);
            else return 0;
        }
        return node->endWith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i]))
                node = node->getChar(word[i]);
            else    
                return 0;
        }
        return node->startWith;
    }

    void erase(string &word){
        // Write your code here.
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->getChar(word[i]);
                node->decStartWith();
            }
            else return;
        }
        node->decEndWith();
    }
};
