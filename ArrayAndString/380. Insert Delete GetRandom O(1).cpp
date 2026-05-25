class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.count(val)) {
            return false;
        }
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }

        int idx = m[val];
        int lstIdx = v.size() - 1;


        int temp = v[lstIdx];
        v[lstIdx] = val;
        v[idx] = temp;
        m[temp] = idx;

        m.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand() % v.size();
        return v[idx];
    }
};
