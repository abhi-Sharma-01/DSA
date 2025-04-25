class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;// agar 2 point hai i.e one straight line 
        int result=0;

        for(int i=0;i<n;i++){// for each find max slope
            unordered_map<double,int> mapp;  // we need to update map again for next set of slope maintaining only (New map for each point i)
            double x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1;j<n;j++){
                
                double x2 = points[j][0], y2 = points[j][1];
                double  slope;
                if(x2-x1 == 0) {
                    slope = INT_MAX; // infinity
                }else{
                    slope = (y2-y1)/(x2-x1);  // we need to convert all the points in double so that division give double 
                }
                mapp[slope]++;
                result = max(result,mapp[slope]);
            }
        }
        return result+1;

    }
};