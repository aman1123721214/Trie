#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = 0;
    void putChar(char ch, Node *node){
        links[ch-'a'] = node;
    }

    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }

    Node *getChar(char ch){
        return links[ch-'a'];
    }
};

int countDistinctSubstring(string &s){
    //Your code here
    Node *root = new Node();
    int count = 0;
    for(int i = 0; i<s.size(); i++){
        Node *node = root;
        for(int j = i; j<s.size(); j++){
            if(!node->containsKey(s[j])){
                node->putChar(s[j], new Node());
                count++;
            }
            node = node->getChar(s[j]);
        }
    }
    return count+1;
}

int main(){
    int t; cin>>t;
    vector<int> ans;
    while(t--){
        string s;
        cin>>s;
        ans.push_back(countDistinctSubstring(s));
    }
    cout<<"ans: "<<endl;
    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}