#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> children;

    TrieNode(char d){
        data = d;
        isTerminal = false;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode('\0');
        numWords = 0;
    }
    void addWordHelper(char *word,TrieNode*root){
        ///Base Case
        if(word[0]=='\0'){
            root->isTerminal = true;
            return;
        }
        ///Recursive Case
        char currentChar = word[0];
        TrieNode* child;

        if(root->children.find(currentChar)==root->children.end()){
            child = new TrieNode(currentChar);
            root->children[currentChar] = child;
        }
        else{
            child = root->children.find(currentChar)->second;

        }
        addWordHelper(word+1,child);

    }

    void addWord(char *word){
        addWordHelper(word,root);

    }
    bool searchWord(char *word){

        TrieNode* node = root;
        for(int i=0;word[i]!='\0';i++){
            ///Not found
            if(node->children.find(word[i])==node->children.end()){
                return false;
            }
            node = node->children.find(word[i])->second;
        }
        ///Return true if terminal is true
        return node->isTerminal;
    }

};

int main(){

    char words[][10] = {"a","ape","apple","not","code","co","man","mango"};
    char searchWords[][10] = {"a","aple","code","cod","no"};

    Trie t;
    for(int i=0;i<8;i++){
        t.addWord(words[i]);
    }

    for(int i=0;i<5;i++){
        if(t.searchWord(searchWords[i])){
            cout<<searchWords[i]<<" found "<<endl;
        }
        else{
            cout<<searchWords[i]<<" Not found "<<endl;
        }

    }


return 0;
}

