// This takes time O(klogn) where n=total no. of elements and k = no. of top elements required.


class Solution {
public:
    struct node{
        int no;
        int freq;
        node(int a,int b)
        {
            no=a;
            freq=b;
        }
    };
    struct compare{
        bool operator()(node const& a, node const& b){
            return a.freq<b.freq;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        priority_queue<node,vector<node>,compare> maxHeap;
        for (auto x:umap){                              //  
            maxHeap.push(node(x.first,x.second));       //   O(n)
        }                                               //
        vector<int> ans;
        while(k--){
            node temp=maxHeap.top();   //
            ans.push_back(temp.no);    //       O(klogn)  , logn for heapify and 
            maxHeap.pop();             //       k times it is being done
        }

        return ans;
    }
};