#include "list_node.h"
#include <gtest/gtest.h>

class Test : public ::testing::Test
{
public:
    void SetUp() override
    {
        list_ = new ListNode();
    }

    void TearDown() override
    {
        delete list_;
    }

protected:
    ListNode* list_;
};

ListNode* removeElements(ListNode* head, int val)
{
    while (head->val == val)
    {
        ListNode * p = head;
        head = head->next;
        delete p;
    }

    ListNode *p1, *p2;
    p1 = p2 = head;
    p1 = p1->next;
    while(p1)
    {
        if (p1->val == val)
        {
            ListNode *p = p1;
            p2->next = p1->next;
            p1 = p2->next;
            delete p;
        }
        else
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return head;
}

TEST_F (Test, test1)
{
    list_->addAtHead(1);
    list_->addAtTail(2);
    list_->addAtTail(6);
    list_->addAtTail(3);
    list_->addAtTail(4);
    list_->addAtTail(5);
    list_->addAtTail(6);

    list_ = removeElements(list_, 6);

    ASSERT_EQ(std::vector<int>({1,2,3,4,5}), list_->getVector());
}

TEST_F (Test, test2)
{
    std::vector<int> list_vec = {1,1,1,1,1,1,1};
    for (int i : list_vec)
        list_->addAtTail(i);

    ListNode * l1 = removeElements(list_, 1);

    ASSERT_EQ(nullptr, l1);

    ListNode * l2 = removeElements(list_, 2);

    ASSERT_EQ(list_vec, l2->getVector());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}