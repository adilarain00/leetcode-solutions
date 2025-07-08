class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int c=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                c++;
            }
            if(m.find(sum-k)!=m.end()){
                c+=m[sum-k];
            }
            m[sum]++; 
        }
        return c;
    }
};