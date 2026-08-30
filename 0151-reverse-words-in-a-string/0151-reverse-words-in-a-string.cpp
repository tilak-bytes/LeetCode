class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                ans+=s[i];
            }
            else if(!ans.empty()){
                words.push_back(ans);
                ans="";
            }
        }
        if(!ans.empty()){
            words.push_back(ans);
        }
        reverse(words.begin(),words.end());
        string result="";
        for(int i=0;i<words.size();i++){
            result+=words[i];
            if(!result.empty() && i<words.size()-1)result+=' ';
        }
        return result;
    }
};