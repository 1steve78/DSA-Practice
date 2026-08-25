class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> st;
        for(int x : nums){
           if(st.find(x)==st.end()) st.insert(x);
        }

        int mul =1;
        while(st.find(k*mul)!=st.end()){
            mul++;
        }
        return mul*k;
    }
};