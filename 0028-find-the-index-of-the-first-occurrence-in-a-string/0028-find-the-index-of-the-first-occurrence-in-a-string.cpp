class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                if(m==1)return i;
                i++;
                int j=1;
                while(haystack[i]==needle[j] && j<m){
                    if(j==m-1)return i-m+1;
                    i++,j++;
                }
                i=i-j;
            }
        }
        return -1;
        
    }
};