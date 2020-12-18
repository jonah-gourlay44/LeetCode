class ListNode
{
public:
    ListNode();
    ListNode(int x);

    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void print();
    std::vector<int> getVector();

private:
    int val;
    ListNode * next;
};