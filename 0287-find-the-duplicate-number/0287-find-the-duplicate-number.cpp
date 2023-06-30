class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            if(umap.find(nums[i])!=umap.end()){
                return nums[i];
            }else{
                umap[nums[i]]++;
            }
        }

        return -1;
    }
};