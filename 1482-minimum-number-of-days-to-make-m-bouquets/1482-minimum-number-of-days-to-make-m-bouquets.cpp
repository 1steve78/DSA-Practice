class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k,int days){
        int cnt = 0; 
        int ans =0;

        for(int i = 0 ; i< bloomDay.size() ; i++){
            if(bloomDay[i]<=days){
                cnt++;
            }else{
                ans += (cnt/k);
                cnt =0;
            }
        }
        ans += (cnt/k);
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        

        if ((long long)m * k > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high -low)/2;

            if(possible(bloomDay,m,k,mid)){
                ans = min(mid,ans);
                high = mid-1;
            }else{
                low = mid+1;
            }

        } 
        return ans;
    }
};