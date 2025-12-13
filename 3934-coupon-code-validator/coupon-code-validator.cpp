class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

        // Fixed order for businessLine
        unordered_map<string,int> order = {
            {"electronics",0}, {"grocery",1},
            {"pharmacy",2}, {"restaurant",3}
        };

        vector<pair<int,string>> valid;

        for(int i=0;i<n;i++){
            // check active
            if(!isActive[i]) continue;

            // check businessLine
            if(order.find(businessLine[i]) == order.end()) continue;

            // check code validity
            if(code[i].empty()) continue;
            bool ok = true;
            for(char c: code[i]){
                if(!(isalnum(c) || c=='_')) { ok=false; break; }
            }
            if(!ok) continue;

            valid.push_back({order[businessLine[i]], code[i]});
        }

        // sort by businessLine order, then lexicographically
        sort(valid.begin(), valid.end(), [](auto &a, auto &b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        // collect result
        vector<string> ans;
        for(auto &p: valid) ans.push_back(p.second);
        return ans;
    }
};
