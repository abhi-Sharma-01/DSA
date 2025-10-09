class Solution {
public:
    int romanToInt(string s) {

        // Method 1 : using the switch case 
        // Method 2 : Using the map
        unordered_map<char,int> mapp;
        mapp['I'] = 1;mapp['V'] = 5;mapp['X'] = 10;mapp['L'] = 50;mapp['C'] = 100;mapp['D'] =500;mapp['M'] = 1000;
        int n = s.size();
        int res =0;
        int prev =0;
        // // for loop : using the switch 
        // for(int i= n-1;i>= 0;--i){
        //     int val = 0;
        //     switch(s[i]){
        //         case 'I':
        //             val = 1;
        //             break;
        //         case 'V':
        //             val = 5;
        //             break;
        //         case 'X':
        //             val = 10;
        //             break;
        //         case 'L':
        //             val = 50;
        //             break;
        //         case 'C':
        //             val = 100;
        //             break;
        //         case 'D':
        //             val = 500;
        //             break;
        //         case 'M':
        //             val = 1000;
        //             break;
        //     }   
        //     if(val<prev){
        //         res -= val;
        //     }else{
        //         res+= val;
        //     }
        //     prev = val;                    
        // }
        // for loop : using the mapp
        for(int i =n-1;i>=0;i--){
            int val = mapp[s[i]];
            if(val  < prev){
                res -= val;
            }else{
                res += val;
            }
            prev = val;
        }
        return res;        
    }
};