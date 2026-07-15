class Solution {
private:
    bool bs(vector<int>&mat,int col,int target){
        int low=0;
        int high=col-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(mat[mid]==target){return true;}
            else if(mat[mid]>target){high=mid-1;}
            else{low=mid+1;}
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int cr=0;
        while(cr<r){
            if(matrix[cr][0]<=target && matrix[cr][c-1]>=target){
                if(bs(matrix[cr],c,target)==true){return true;}
                else{return false;}
            }
            else if(target>matrix[cr][c-1]){cr++;}
            else{return false;}
        }
        return false;
    }
};