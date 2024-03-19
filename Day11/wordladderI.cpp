//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        //first we will create a queue that stores word and steps;
        queue<pair<string,int>> q;
        //push startword in to queue with steps 1;
        q.push({startWord,1});
        //create a set that stores all words in wordlist
        set <string> st(wordList.begin(),wordList.end());
        //remove that starting word from the set
        st.erase(startWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            //change all the characters in the word and check if word is targetword;
            for(int i=0;i<word.size();i++){
                //storing value as temporary coz after all iterations we need to keep value as same as prev
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    //replace the word[i] character with new char
                    word[i]=ch;
                    //checks if word present in the set or not
                    //if yes then its executes
                    //if given word is equal to the last word in set then it doesn't execute the condition
                    if(st.find(word) != st.end()){
                        //erase that word from set;
                        st.erase(word);
                        //and push that into queue;
                        q.push({word,steps+1});
                    }
                }
                //after that traversal we will keep that same
                word[i]=original;
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends