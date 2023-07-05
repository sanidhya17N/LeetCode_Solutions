class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
      
        int j=0;
        if(n==1)return strs[0];
        while(true){
            for(int i=1;i<n;i++){
                if(strs[i][j]==NULL || strs[i-1][j]==NULL)return ans;
                if(strs[i][j]!=strs[i-1][j]){
                    return ans;
                }
            }
            ans+=strs[0][j];
            j++;

        }

        return ans;
    }
};