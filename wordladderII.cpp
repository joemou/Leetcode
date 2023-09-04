#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> steps{{beginWord, 1}}; // calc the steps
        unordered_map<string, vector<string>> parents;
        queue<string> todo;
        vector<vector<string>> ans;

        if (!dict.count(endWord)) {
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);

        todo.push(beginWord);

        const int l = beginWord.size();
        bool found = false;
        int step = 0;

        while (!todo.empty() && !found) {
            step++;
            for (int i = todo.size(); i > 0; i--) {
                string word = todo.front();
                string prev = word;
                todo.pop();
                for (int k = 0; k < l; k++) {

                    for (int j = 0; j < 26; j++) {
                        word[k] = 'a' + j;
                        if (word == endWord) {
                            found = true;
                            parents[word].push_back(prev);
                        } else {
                            if (steps.count(word) && step < steps[word]) {
                                parents[word].push_back(prev);
                            }
                        }
                        if (!dict.count(word)) {
                            continue;
                        }
                        dict.erase(word);
                        todo.push(word);
                        steps[word] = step + 1;
                        parents[word].push_back(prev);
                    }
                    word = prev;
                }

            }
        }
        if (found) {
            vector<string> curr{endWord};
            getpath(endWord, beginWord, parents, curr, ans);
        }
        return ans;
    }

private:
    void getpath(string word, string beginWord, unordered_map<string, vector<string>>& parents, vector<string> curr, vector<vector<string>>& ans) {
        if (word == beginWord) {
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
        }
        for (string& p : parents[word]) {
            curr.push_back(p);
            getpath(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }
    }
};

/* memory limit
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end()),clean;
        queue<string> todo;
        vector<vector<string>> ans;
        queue<vector<string>> path;
        vector<string> t,p{beginWord};
        

        path.push(p);
        int flag=0;
        string c;
        
        if(dict.find(endWord)==dict.end()){
            return ans;
        }

        todo.push(beginWord);
        dict.erase(beginWord);
        while(!todo.empty()&&flag==0){

            for (string w:clean){
                dict.erase(w);
            }

            clean.clear();

            int m = todo.size();

            for (int i = 0; i < m;i++){
                
                t = path.front();
                path.pop();
                string word = todo.front();
                todo.pop();
                c=word;
                for(int l=0;l<word.size();l++){
                    
                    for(int k=0;k<26;k++){
                        word[l]='a'+k;
                        if(dict.find(word)!=dict.end()){
                            todo.push(word);

                            vector<string> temp = t;
                            temp.push_back(word);
                            path.push(temp);


                            clean.insert(word);
                            if(temp.back()==endWord){
                                flag = 1;
                                ans.push_back(temp);
                            }
                        }
                    }
                    word=c;
                }
            }
        }
        return ans;
    }
};
*/

