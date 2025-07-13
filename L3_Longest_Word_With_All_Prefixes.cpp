#include<bits/stdc++.h>
#include <bits/stdc++.h> 
using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch) { return (links[ch - 'a'] != nullptr); }

    Node *get(char ch) { return links[ch - 'a']; }
    void put(char ch, Node *node) { links[ch - 'a'] = node; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie {
private:
  Node *root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for (char ch : word) {
        if (!node->containsKey(ch)) {
            node->put(ch, new Node());
        }
        node = node->get(ch);
        }
        node->setEnd();
    }

 
    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        for (char ch : word) {
        if (node->containsKey(ch)) {
            node = node->get(ch);
            if (!node->isEnd())
            return false;
        } else {
            return false;
        }
        }
        return true;
    }
};
class Solution{
    public:
    string completeString(int n, vector<string> &words) {
  
    Trie *obj = new Trie();
    for (const auto &word : words)
        obj->insert(word);
    string longest = "";
    for (const auto &word : words) {
        if (obj->checkIfAllPrefixExists(word)) {
        if (word.size() > longest.size() ||
            (word.size() == longest.size() && word < longest)) {
        
            longest = word;
        }
        }
    }
    if (longest.empty())
        return "None";
    return longest;
    }
};

int main(){
    Solution obj;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> a(n);
        for(int i = 0; i<n; i++){
            string word;
            cin>>word;
            a.push_back(word);
        }

        cout<<obj.completeString(n, a);
    }
    return 0;
}