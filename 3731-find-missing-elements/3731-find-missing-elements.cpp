class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int>hash(maxi+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int m=hash.size();
        int i=0;
        vector<int>ls;
        while(i<m && hash[i]==0)i++;
        while(i<m){
            if(hash[i]==0)ls.push_back(i);
            i++;
        }
        return ls;
    }
};