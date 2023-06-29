class Solution {
public:
    // static bool comparator(vector<int> v1,vector<int> v2){
    //     if(v1[0]<=v2[0])return true;
    //     else return false;
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());

        vector<int> temp(2);
        temp[0]=intervals[0][0];
        temp[1]=intervals[0][1];
        for(int i=1;i<n;i++){
           if(intervals[i][0]<=temp[1]){
               if(temp[1]<intervals[i][1]){
                   temp[1]=intervals[i][1];
               }
           }else{
               ans.push_back(temp);
               temp[0]=intervals[i][0];
               temp[1]=intervals[i][1];
           } 
        }
        ans.push_back(temp);
        return ans;        
    }
};