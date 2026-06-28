class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(wordSet.find(endWord) == wordSet.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while(!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            for(int i = 0 ; i < word.size() ; i++){
                string newWord = word;

                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    if(ch == word[i]) continue;

                    newWord[i] = ch;

                    if(newWord == endWord) return steps + 1;

                    if(wordSet.find(newWord) != wordSet.end()){
                        wordSet.erase(newWord);
                        q.push({newWord, steps + 1});
                    }
                }
            }
        }
        return 0;
    }
};