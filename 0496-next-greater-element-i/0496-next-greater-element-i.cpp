class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        stack<int> st;
        unordered_map<int,int> umap;
        for(int i=0;i<nums1.size();i++){
            umap[nums1[i]]=i;
        }

        int i=nums2.size()-1;
  
        while(i>=0){
            if(st.empty()){
                st.push(nums2[i]);
                i--;
                continue;
            }
            if(st.top()<nums2[i]){
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(nums2[i]);
                    i--;
                    continue;
                }
                ans[umap[nums2[i]]]=st.top();
                st.push(nums2[i]);
                i--;
            }else{
                if(umap.find(nums2[i])==umap.end()){
                    st.push(nums2[i]);
                    i--;
                    continue;

                }
                ans[umap[nums2[i]]]=st.top();
                st.push(nums2[i]);
                i--;
            }


        }

        return ans;
    }
};