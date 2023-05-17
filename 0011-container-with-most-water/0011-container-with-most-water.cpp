class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int n=height.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int vol=(j-i)*min(height[i],height[j]);
            ans=max(vol,ans);
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};