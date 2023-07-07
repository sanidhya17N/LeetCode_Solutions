class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=a.length();
        int n=b.length();

        bool found=false;
        int count;

        for(int i=0;i<m;i++){
            int j=i;
            int k=0;
            count=1;

            while(k<n && a[j]==b[k]){
                if(k==n-1){
                    found=true;
                    break;
                }

                j=(j+1)%m;
                if(j==0)count++;
                k++;
            }

            if(found)return count;
        }

        return -1;

    }
};