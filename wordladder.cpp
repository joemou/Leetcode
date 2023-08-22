#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> todo;
        string word;

        todo.push(beginWord);

        int ans=1;

        while(!todo.empty()){
            int m=todo.size();
            for(int n=0;n<m;n++){
                word=todo.front();
                todo.pop();
                if (word == endWord) {
                    return ans;
                }
                for(int i=0;i<word.size();i++){
                    char c=word[i];
                    for(int k=0;k<26;k++){
                        word[i]='a'+k;
                        if(dict.find(word)!=dict.end()){
                            todo.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i]=c;
                }
            }
            ans++;
        }
        return 0;    
    }
};