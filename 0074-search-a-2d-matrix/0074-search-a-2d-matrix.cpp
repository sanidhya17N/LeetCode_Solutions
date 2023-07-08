class Solution {
public:
    int binarySearch(vector<int> nums,int target){
        int i=0;
        int j=nums.size()-1;
        int mid=i+(j-i)/2;
        while(i<=j){
            if(nums[mid]==target)return true;
            else if(nums[mid]<target)i=mid+1;
            else j=mid-1;
            mid=i+(j-i)/2;

        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=m-1;
        int mid=i+(j-i)/2;
        while(i<=j){
            if(matrix[mid][0]>target){
                j=mid-1;
            }
            else if(matrix[mid][0]<target && matrix[mid][n-1]<target){
                i=mid+1;
            }
            else{
                if(matrix[mid][0]==target)return true;
                if(matrix[mid][n-1]==target)return true;
                return binarySearch(matrix[mid],target);
            }
            mid=i+(j-i)/2;
        }

        return false;

    }
};