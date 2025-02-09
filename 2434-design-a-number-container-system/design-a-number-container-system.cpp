class NumberContainers {
public:
    unordered_map<int, int> idx_num;
    unordered_map<int, set<int>> num_idxs;

    NumberContainers() {}

    void change(int idx, int num) {
        if (idx_num.find(idx) != idx_num.end()) {
            int old_num = idx_num[idx];
            num_idxs[old_num].erase(idx);
            if (num_idxs[old_num].empty()) {
                num_idxs.erase(old_num);
            }
        }
        idx_num[idx] = num;
        num_idxs[num].insert(idx);
    }

    int find(int num) {
        if (num_idxs.find(num) != num_idxs.end() && !num_idxs[num].empty()) {
            return *num_idxs[num].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
