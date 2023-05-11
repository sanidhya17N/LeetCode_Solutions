class Solution {
public:
     void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        
        visited[r][c]=1;
        int dr[4]={0,-1,0,1};
        int dc[4]={1,0,-1,0};
        for(int i=0;i<4;i++){
            if(r+dr[i]<0 || r+dr[i]>n-1 || c+dc[i]<0 || c+dc[i]>m-1)continue;
            if(grid[r+dr[i]][c+dc[i]]!='1'){
                visited[r+dr[i]][c+dc[i]]=1;
                continue;
            }
            if(visited[r+dr[i]][c+dc[i]]==1)continue;
            dfs(grid,visited,r+dr[i],c+dc[i]);
        }
        return;

    }


    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;
        vector<vector<int>> visited(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1){
                    continue;
                }
                if(grid[i][j]=='1'){
                    ans+=1;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
        
    }
};