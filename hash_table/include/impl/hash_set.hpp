#include <vector>
#include <math.h>

using namespace std;

class HashSet 
{
public:
    HashSet();

    void add(int key);

    void remove(int key);

    bool contains(int key);

private:
    vector<vector<int> > set_;
    
    int hash(int key);
    bool search(vector<int> arr, int key, int& loc);
};

HashSet::HashSet()
    : set_(100)
{}

int HashSet::hash(int key)
{
    return key % 100;
}

bool HashSet::search(vector<int> arr, int key, int& loc)
{
    int mid = arr.size() / 2;
    vector<int>::const_iterator start;
    vector<int>::const_iterator end;
     
    if (arr.size() == 0) 
        return false;
    else if (arr.size() == 1 && arr[0] != key)
        return false;
    else if (arr[0] == key)
        return true;
    else if (arr[mid] == key) {
        loc += mid;
        return true;
    } else if (arr[mid] < key) {
        loc += mid;
        start = arr.begin() + mid;
        end = arr.end();
    } else {
        start = arr.begin();
        end = arr.begin() + mid;
    }
    return search(vector<int> (start, end), key, loc);
}

void HashSet::add(int key)
{
    vector<int>& bin = set_[hash(key)];
    int loc = 0;

    if (bin.size() < 1) {
        bin.push_back(key);
    } else if (search(bin, key, loc)) {
        return;
    } else {
        vector<int>::const_iterator iter = bin.begin() + loc;
        key < bin[loc] ? bin.insert(iter, key) : bin.insert(iter+1,key);
    }
}

void HashSet::remove(int key)
{
    vector<int>& bin = set_[hash(key)];
    int loc = 0;

    if (bin.size() < 1) {
        return;
    } else if (!search(bin, key, loc)) {
        return;
    } else {
        vector<int>::const_iterator iter = bin.begin() + loc;
        bin.erase(iter);
    }
}

bool HashSet::contains(int key)
{
    vector<int> bin = set_[hash(key)];
    int loc = 0;

    if (bin.size() < 1)
        return false;
    
    return search(bin, key, loc);
}