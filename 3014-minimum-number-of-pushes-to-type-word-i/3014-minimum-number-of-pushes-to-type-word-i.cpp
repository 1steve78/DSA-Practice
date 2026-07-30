class Solution {
public:
    int minimumPushes(string word) {
        int cost = 0; 
        for(int i = 0 ; i< word.size() ; i++){
            cost += (i/8)+1;
        }
        return cost;
    }
};