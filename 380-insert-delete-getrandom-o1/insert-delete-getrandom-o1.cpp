class RandomizedSet {
public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        bool result = numMap.find(val) == numMap.end();
        if (result) {
            numMap[val] = numList.size();
            numList.push_back(val);
        }
        return result;
    }

    bool remove(int val) {
        bool result = numMap.find(val) != numMap.end();
        if (result) {
            int index = numMap[val];
            int lastval = numList.back();
            numList[index] = lastval;
            numList.pop_back();
            numMap[lastval] = index;
            numMap.erase(val);
        }
        return result;
    }

    int getRandom() {
        return numList[rand() % numList.size()];
    }

private:
    unordered_map<int, int> numMap;
    vector<int> numList;
};

