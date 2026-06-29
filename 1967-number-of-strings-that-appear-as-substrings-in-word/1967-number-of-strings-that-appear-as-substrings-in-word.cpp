class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        
        int cnt = 0;
        int n =patterns.size();

        for(int i = 0 ; i< n ; i++){
            string st = patterns[i];
            if (word.find(st) != string::npos) {
               cnt++;
            } 
        }
        return cnt;
    }
};