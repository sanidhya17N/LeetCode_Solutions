class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        while(l<=r){
            int mid=r+(l-r)/2;
            if(mid<n-1 && nums[mid]==nums[mid+1]){
                if(mid%2==0)l=mid+1;
                else r=mid-1;
            }else if (mid>0 && (nums[mid]==nums[mid-1])){
                if(mid%2==0)r=mid-1;
                else l=mid+1;
            }else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};