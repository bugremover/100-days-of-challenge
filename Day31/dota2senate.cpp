class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<bool> ord;
        bool i;
        int count[2][2] = {0}; 
        for(char ch: senate) {
            i = ch == 'R';
            ord.push(i);
            count[0][i]++;
        }
        while(count[0][0] && count[0][1]) {
            i = ord.front();
            ord.pop();
            if(count[1][i])
                count[1][i]--;
            else {
                count[0][!i]--;
                count[1][!i]++;
                ord.push(i);
            }
        }
        if(count[0][0])
            return "Dire";
        return "Radiant";
    }
};