#include <iostream>

using namespace std;

#include <vector>

class ListNode
{
public:
    ListNode();
    ListNode(int x);

    int get(int index);
    ListNode * getNode(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void print();
    std::vector<int> getVector();

    int val;
    ListNode * next;
};

ListNode::ListNode()
    : next(nullptr)
    , val(-1)
{}

ListNode::ListNode(int x)
    : next(nullptr)
    , val(x)
{}

int ListNode::get(int index)
{
    if (index < 0)
        return -1;
    
    ListNode * cur_node = this;
    for (int i = 0; i < index; ++i)
    {
        if (!cur_node->next)
            return -1;
        cur_node = cur_node->next;
    }

    return cur_node->val;
}

ListNode * ListNode::getNode(int index)
{
    if (index < 0)
        return nullptr;

    ListNode * cur_node = this;
    for (int i = 0; i < index; ++i)
    {
        if (!cur_node->next)
            return nullptr;
        cur_node = cur_node->next;
    }

    return cur_node;
}

void ListNode::addAtHead(int val)
{
    if (this->val == -1)
        this->val = val;
    else
    {
        ListNode * new_node = new ListNode();
        new_node->val = this->val;
        new_node->next = this->next;
        this->val = val;
        this->next = new_node;
    }
}

void ListNode::addAtTail(int val)
{
    if (this->val == -1)
        this->val = val;
    else
    {
        ListNode * new_node = new ListNode();
        new_node->val = val;
        ListNode * cur_node = this;
        while(cur_node->next)
            cur_node = cur_node->next;
        cur_node->next = new_node;
    } 
}

void ListNode::addAtIndex(int index, int val)
{
    if (index < 0)
        return;

    if (index == 0 )
    {
        addAtHead(val);
        return;
    }

    ListNode * cur_node = this;
    ListNode * prev_node = this;
    int i = 0;
    for (; i < index; ++i)
    {
        if (!cur_node->next)
            break;
        if (i > 0)
            prev_node = prev_node->next;
        cur_node = cur_node->next;
    }

    if (i < index - 1)
        return;
    if (i == index - 1)
    {
        if (i > 0)
            prev_node = prev_node->next;
        cur_node = cur_node->next;
    }

    ListNode * new_node = new ListNode();
    new_node->val = val;
    new_node->next = cur_node;
    prev_node->next = new_node;
}

void ListNode::deleteAtIndex(int index)
{
    if (index < 0)
        return;

    if (index == 0)
    {
        if (!this->next)
            this->val = -1;
        else
        {
            ListNode * cur_node = this->next;
            this->val = this->next->val;
            this->next = this->next->next;
            delete cur_node;
        }
        return;
    }

    ListNode * cur_node = this;
    ListNode * prev_node = this;
    int i = 0;
    for (; i < index; ++i)
    {
        if (!cur_node->next)
            break;
        if (i > 0)
            prev_node = prev_node->next;
        cur_node = cur_node->next;
    }

    if (i == index)
    {
        prev_node->next = cur_node->next;
        delete cur_node;
    }
}

void ListNode::print()
{
    ListNode * cur = this;
    string list_str = "[";
    while(cur->next)
    {
        list_str += to_string(cur->val) + ",";
        cur = cur->next;
    }
    list_str += to_string(cur->val) + "]";

    std::cout << list_str << std::endl;
}

std::vector<int> ListNode::getVector()
{
    ListNode * cur = this;
    std::vector<int> out;

    if (cur->val < 0)
        return out;

    while(cur->next)
    {
        out.push_back(cur->val);
        cur = cur->next;
    }
    out.push_back(cur->val);

    return out;
}