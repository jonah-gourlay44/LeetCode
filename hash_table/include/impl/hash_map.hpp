#include <vector>
#include <tuple>

using namespace std;

class HashMap 
{
public: 
    HashMap();

    void put(int key, int value);

    int get(int key);

    void remove(int key);

private:
    vector<vector<tuple<int, int> > > map_;

    int hash(int key);

    bool search(vector<tuple<int, int> > arr, int key, int& loc);
};

HashMap::HashMap()
    : map_(100)
{}

int HashMap::hash(int key)
{
    return key % 100;
}

bool HashMap::search(vector<tuple<int, int> > arr, int key, int& loc)
{
    int mid = arr.size() / 2;
    vector<tuple<int, int> >::const_iterator start;
    vector<tuple<int, int> >::const_iterator end;

    if (arr.size() == 0)
        return false;
    else if (arr.size() == 1 && std::get<0>(arr[0]) != key)
        return false;
    else if (std::get<0>(arr[0]) == key)
        return true;
    else if (std::get<0>(arr[mid]) == key) {
        loc += mid;
        return true;
    } else if (std::get<0>(arr[mid]) < key) {
        loc += mid;
        start = arr.begin() + mid;
        end = arr.end();
    } else {
        start = arr.begin();
        end = arr.begin() + mid;
    }
    return search(vector<tuple<int, int> > (start, end), key, loc);
}

void HashMap::put(int key, int value)
{
    tuple<int, int> entry = std::make_tuple(key, value);
    vector<tuple<int, int> >& bin = map_[hash(key)];
    int loc = 0;

    if (bin.size() < 1) {
        bin.push_back(entry);
    } else if (search(bin, key, loc)) {
        std::get<1>(bin[loc]) = value;
    } else {
        vector<tuple<int, int> >::const_iterator iter = bin.begin() + loc;
        key < std::get<0>(bin[loc]) ? bin.insert(iter, entry) : bin.insert(iter+1, entry);
    }
}

int HashMap::get(int key)
{
    vector<tuple<int, int> > bin = map_[hash(key)];
    int loc = 0;

    if (bin.size() < 1)
        return -1;
    else if (!search(bin, key, loc)) {
        return -1;
    } else {
        return std::get<1>(bin[loc]);
    }
}

void HashMap::remove(int key)
{
    vector<tuple<int, int> >& bin = map_[hash(key)];
    int loc = 0;

    if (bin.size() < 1) 
        return;
    else if (!search(bin, key, loc)) {
        return;
    } else {
        vector<tuple<int, int> >::const_iterator iter = bin.begin() + loc;
        bin.erase(iter);
    }
}