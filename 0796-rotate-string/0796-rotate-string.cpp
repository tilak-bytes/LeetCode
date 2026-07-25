class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        string forCheck = s + s;
        return forCheck.find(goal) != string::npos;    //if string is found
    }
};