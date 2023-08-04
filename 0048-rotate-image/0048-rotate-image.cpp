class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n=matrix.size();
        int temp=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
    }
    void treverse(vector<int>& row){
        int n=row.size();
        int temp;
        for(int i=0;i<n/2;i++){
            temp=row[i];
            row[i]=row[n-i-1];
            row[n-i-1]=temp;
        }
    } 
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        transpose(matrix);
        for(int i=0;i<n;i++){
            treverse(matrix[i]);
        }

    }
};