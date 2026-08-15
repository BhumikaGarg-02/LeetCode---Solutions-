class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         int k=nums2.size();
         unordered_map<int,int>mpp;
         stack<int>st;
         for(int i=k-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]]=-1;
            }
            else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
         }
         int n=nums1.size();
         vector<int>ans;
         for(int i=0;i<n;i++){
           ans.push_back(mpp[nums1[i]]);
         }
         return ans;
    }
};