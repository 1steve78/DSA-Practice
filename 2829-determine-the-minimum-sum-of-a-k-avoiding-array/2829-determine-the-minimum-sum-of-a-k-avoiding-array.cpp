class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> st;
        
        int i = 1;
        int cnt = 0;
        while(cnt < n){
            if(st.find(k-i) != st.end()) {
                i++;
                continue;
            }
            
            st.insert(i);
            i++;
            cnt++;

        }
        int ans = 0 ;
        for(int x : st) ans += x;

        return ans;
    }
};