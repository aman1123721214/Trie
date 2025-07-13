#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[2];
    void put(int bit, Node *node){
        links[bit] = node;
    }

    Node *getBit(int bit){
        return links[bit];
    }

    bool containsBit(int bit){
        return (links[bit] != NULL);
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node;
    }
    void insertNum(int num){
        Node *node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i) &1;
            if(!node->containsBit(bit))
                node->put(bit, new Node);
            node = node->getBit(bit);
        }
    }

    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i = 31; i>=0; i--){
            int bit = (num>>i) &1;
            if(node->containsBit(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->getBit(1-bit);
            }
            else node = node->getBit(bit);
        }
        return maxNum;
    }
};


int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here.   
    Trie trie;
    for(int i = 0; i<n; i++)
        trie.insertNum(arr1[i]);
    int maxi = 0;
    for(int i = 0; i<m; i++)
        maxi = max(maxi, trie.getMax(arr2[i]));
    return maxi;
}


int main(){
    int t; cin>>t;
    vector<int> ans;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> arr1(n), arr2(m);
        for(int i = 0; i<n; i++) cin>>arr1[i];
        for(int i = 0; i<m; i++) cin>>arr2[i];
        int res = maxXOR(n, m, arr1, arr2);
        ans.push_back(res);
    }

    for(auto it: ans)
        cout<<it<<endl;
    return 0;
}