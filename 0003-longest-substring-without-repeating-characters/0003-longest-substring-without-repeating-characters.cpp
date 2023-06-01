class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i=0;
       int j=0;
       unordered_map<int,int> umap;
       int result=0;
       while(j<s.size()){
            while(umap.find(s[j])!=umap.end()){
               umap.erase(s[i]);
               i++;
            }
            umap[s[j]]++;
            result=max(result,j-i+1);
            j++;
       }

       return result;
    }
};