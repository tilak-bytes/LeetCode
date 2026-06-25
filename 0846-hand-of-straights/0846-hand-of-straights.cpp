class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for(auto h : hand) freq[h]++;

        while(!freq.empty()){
            int start = freq.begin() -> first;
            for(int i = start ; i < start + groupSize ; i++){
                if(freq.find(i) == freq.end()) return false;
                freq[i]--;
                if(freq[i] == 0) freq.erase(i);
            }
        }
        return true;
    }
};