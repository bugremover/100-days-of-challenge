#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char, int> charCount;
        for (char ch : s) {
            charCount[ch]++;
        }        
        for (char ch : order) {
            if (charCount.find(ch) != charCount.end()) {
                ans.append(charCount[ch], ch);
                charCount.erase(ch); 
            }
        }        
        for (auto& pair : charCount) {
            ans.append(pair.second, pair.first);
        }
        return ans;
    }
};
