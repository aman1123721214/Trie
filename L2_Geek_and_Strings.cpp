#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *link[26];
    int startWith = 0;

    void putChar(char ch, Node *node){
        link[ch-'a'] = node;
    }

    Node *getchar(char ch){
        return link[ch-'a'];
    }

    bool containsKey(char ch){
        return (link[ch-'a'] != NULL);
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }

    void insertWord(string &word){
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                node->putChar(word[i], new Node);
            node = node->getchar(word[i]);
            node->startWith++;
        }
    }

    int searchWord(string &word){
        Node *node = root;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i]))
                node = node->getchar(word[i]);
            else return 0;
        }
        return node->startWith;
    }

};
class Solution{
public:
    vector<int> prefixCount(int n, int q, string li[], string query[]){
        Trie *trie = new Trie();
        for(int i = 0; i<n; i++){
            string word = li[i];
            trie->insertWord(word);
        }
        vector<int> ans;
        for(int i = 0; i<q; i++){
            string word = query[i];
            ans.push_back(trie->searchWord(word));
        }
        return ans;
    }
};

/*
struct Node{
      Node * links[26];
   
    int cntPrefix=0;
    
    bool containKey(char ch) {
return (links[ch - 'a'] != NULL);
}
    Node * getNode(char ch){
        return links[ch-'a'];
    }
    void putNode(char ch,Node *node){
        links[ch-'a']=node;
    }
   
    void increasePrefix(){
        cntPrefix++;
    }
  
};
class Trie{
    
    public:
    Node * root;
    Trie(){
        // Write your code here.
        root=new Node();
    }
 
    void insert(string &word){
        // Write your code here.
        Node * node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containKey(word[i])){
                node->putNode(word[i],new Node());
            }
            node=node->getNode(word[i]);
            node->increasePrefix();
            
        }
      
    }
 
 
    int search(string &word){
        // Write your code here.
        Node *node=root;
         for(int i=0;i<word.length();i++){
            if(!node->containKey(word[i])){
               return 0;
            }
            node=node->getNode(word[i]);
            
        }
        return node->cntPrefix;
    }
 
    
};
class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        Trie *trie=new Trie();
        for(int i=0;i<N;i++){
            trie->insert(li[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<Q;i++){
            
           ans.push_back(trie->search(query[i])); 
            
        }
        
        return ans;
    }
};
*/