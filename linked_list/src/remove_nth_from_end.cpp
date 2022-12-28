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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if (!head)
        return head;

    ListNode *p1, *p2;
    p1 = p2 = head;
    for (int i = 0; i < n; ++i)
        p2 = p2->next;

    ListNode *p3 = p1;
    while (p2)
    {
        p2 = p2->next;
        if (!p2)
        {
            p3 = p1->next;
            p1->next = p1->next->next;
        }
        else
            p1 = p1->next;
    }

    if (p3 == head)
        head = head->next;
    else
        delete p3;

    return head;
}

TEST_F (Test, test1)
{
    list_->addAtHead(1);
    list_->addAtTail(2);
    list_->addAtTail(3);
    list_->addAtTail(4);
    list_->addAtTail(5);

    list_ = removeNthFromEnd(list_, 2);
    ASSERT_EQ(std::vector<int>({1,2,3,5}), list_->getVector());
}

TEST_F (Test, test2)
{
    list_->addAtHead(1);

    list_ = removeNthFromEnd(list_, 1);
    ASSERT_EQ(list_, nullptr);
}

TEST_F (Test, test3)
{
    list_->addAtHead(1);
    list_->addAtTail(2);

    list_ = removeNthFromEnd(list_, 1);
    ASSERT_EQ(std::vector<int>({1}), list_->getVector());
}

int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}