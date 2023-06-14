class Solution {
public:
    // void mark(vector<vector<int>>& matrix,int i ,int j){
    //     int m =matrix.size();
    //     int n = matrix[0].size();
    //     for(int a=0;a<n;a++){
    //         if(matrix[i][a]!=0){
    //             matrix[i][a]=-1;
    //         }
    //     }
    //     for(int a=0;a<m;a++){
    //         if(matrix[a][j]!=0){
    //             matrix[a][j]=-1;
    //         }
    //     }
    // }

    void setZeroes(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n = matrix[0].size();
        vector<bool> isColumn(m,false);
        vector<bool> isRow(n,false);

        for(int i=0 ;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    isColumn[i]=true;
                    isRow[j]=true;
                }
            }
        }
        for(int i=0 ;i<m;i++){
            for(int j=0;j<n;j++){
                if(isColumn[i] || isRow[j]){
                    matrix[i][j]=0;
                }
            }
        }

    }
};