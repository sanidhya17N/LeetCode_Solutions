
class Solution {
public:

    void findSubsets(vector<vector<int>>& subsets,vector<int>& nums,int index,vector<int>& temp){
        if(index==nums.size()){
            subsets.emplace_back(temp);
            return;
        }
        if(index>0 && nums[index]==nums[index-1] && temp.size()>0 && temp[temp.size()-1]==nums[index]){
            temp.emplace_back(nums[index]);
            findSubsets(subsets,nums,index+1,temp);
            temp.pop_back();
        }else{
            temp.emplace_back(nums[index]);
            findSubsets(subsets,nums,index+1,temp);
            temp.pop_back();
            findSubsets(subsets,nums,index+1,temp);
        }
            
        
        

        return;


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> temp;
        sort(nums.begin(),nums.end());

        findSubsets(subsets,nums,0,temp);
        return subsets;
    }
};