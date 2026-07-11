class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>miss;
        int n=arr.size();
        for(int i=1;i<arr[0];i++){
            miss.push_back(i);
        }
        for(int i=0;i<n-1;i++){
            if(arr[i+1]!=arr[i]+1){
                for(int j=arr[i]+1;j<arr[i+1];j++){
                    miss.push_back(j);
                }
            }
        }
        while(miss.size()<k){
            if(!miss.empty()){
                int i=max(arr.back(),miss.back());
                miss.push_back(i+1);
            }
            else{
                miss.push_back(arr.back()+1);
            }
        }
        return miss[k-1] ;
    }
};