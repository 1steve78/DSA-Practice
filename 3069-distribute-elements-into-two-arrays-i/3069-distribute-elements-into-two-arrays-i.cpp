class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
      
        int k =2;

        vector<int> arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        while(k<nums.size()){
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[k]);
            }else{
                arr2.push_back(nums[k]);
            }
            k++;
        }
        arr1.insert(arr1.end(),arr2.begin(), arr2.end());
        return arr1;
    }
};