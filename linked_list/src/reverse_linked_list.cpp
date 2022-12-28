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

ListNode* reverseList(ListNode* head)
{
    if (!head)
        return nullptr;

    ListNode *p1, *p2;
    p1 = p2 = head;
    while (p1->next)
    {   
        ListNode *cur_head = head;
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = cur_head;
        head = p2;
    }

    return head;
}

TEST_F (Test, test1)
{
    list_->addAtHead(1);
    list_->addAtTail(2);
    list_->addAtTail(3);
    list_->addAtTail(4);
    list_->addAtTail(5);

    list_ = reverseList(list_);
    ASSERT_EQ(std::vector<int>({5,4,3,2,1}), list_->getVector());
}

int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}