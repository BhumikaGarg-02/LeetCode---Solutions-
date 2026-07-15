class Solution {
public:
    int max_el(vector<vector<int>>& mat,int n,int col){
        int index=-1;
        int maxval=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxval){
                maxval=mat[i][col];
                index=i;
            }
        }
        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int row=max_el(mat,n,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>right && mat[row][mid]>left){return{row,mid};}
            else if(mat[row][mid]<left){h=mid-1;}
            else{l=mid+1;}
        }
        return{-1,-1};    
    }
};