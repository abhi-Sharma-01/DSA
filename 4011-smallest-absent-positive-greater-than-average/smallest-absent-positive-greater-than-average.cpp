class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int x:nums){
            sum+= x;
        }
        long long avg = (float)sum/n; //  note yaha par decimal value ka floor ho jata hai so we need to inrease the val which we need to find   real avg == 1.5 but stored as 1only
        // therefore we need to increase by one 
        // cout<<avg<<endl;
        // Note yaha hame agar avg decimal mila hai i.e 
        avg++;
        // cout<<avg<<endl;
        set<int> s(nums.begin(),nums.end());// uniquely store kare ga  Yes, TC - O(logN)

        if(avg<=0)  avg =1;// as we need to return samllest absent positive & greater than avg
        while(true){
            if(s.find(avg) == s.end()) return avg; // agar element .end() tak nahi mile then thats's our answer
            avg++; 
        }

        return -1;

        
    }
};