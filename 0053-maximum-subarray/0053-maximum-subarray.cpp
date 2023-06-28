class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;
        int tempsum=0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            tempsum+=nums[i];
            if(tempsum>sum){
                sum=tempsum;
            }
            if(tempsum<=0){
                tempsum=0;
            }
        }
        return sum;
    }
};