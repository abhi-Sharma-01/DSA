class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {

        // // Approach 1
        // int n = pizzas.size();
        // int Tdays = n/4;
        // sort(pizzas.begin(),pizzas.end());
        // long long Wt_gain = 0;
        // int indx = n,i=1;
        // while(Tdays--){
        //     if(i%2!=0){
        //         indx -= 1;
        //         Wt_gain += pizzas[indx];                
        //     }
        //     else{
        //         indx -= 2;
        //         Wt_gain += pizzas[indx];
        //     }
        //     i++;
        // }
        // return Wt_gain;

        // Note Approach 1 give error in the when we have unequal no of odd even days

        // Approach 2


        sort(pizzas.begin(), pizzas.end());
        int n = pizzas.size();
        int Tdays = n / 4;
        long long Wt_gain = 0;
        int indx = n;

        // Calculate the weight gained on odd days first
        for (int i = 1; i <= Tdays; i += 2) {
            // indx-=1;
            Wt_gain += pizzas[indx-=1];
        }

        // Calculate the weight gained on even days
        for (int i = 2; i <= Tdays; i += 2) {
            // indx -= 2;
            Wt_gain += pizzas[indx-=2];
        }

        return Wt_gain;
    }
};
