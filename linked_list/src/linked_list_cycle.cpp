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
    ListNode * list_;
};

bool hasCycle(ListNode * head)
{
    if (!head || !head->next)
        return false;

    ListNode * p1, * p2;
    p1 = head->next;
    p2 = head;

    int i = 0;
    while (p1 && p2)
    {
        if (p1 == p2)
            return true;

        p1 = p1->next;
        if (i % 2 == 0)
            p2 = p2->next;
        i++;
    }

    return false;
}

bool hasCycle(ListNode * head, ListNode ** p1, ListNode ** p2)
{
    if (!head || !head->next)
        return false;

    *p1 = head->next;
    *p2 = head;

    int i = 0;
    while (*p1 && *p2)
    {
        if (*p1 == *p2)
            return true;

        *p1 = (*p1)->next;
        if (i % 2 == 0)
            *p2 = (*p2)->next;
        i++;
    }

    return false;
}

ListNode* detectCycle(ListNode * head)
{
    ListNode *p1, *p2;
    p1 = p2 = nullptr;
    if (!hasCycle(head, &p1, &p2))
        return nullptr;

    assert(p1 == p2 && p1 && p2);

    int cycle_num = 1;
    p1 = p1->next;
    while (p1 != p2)
    {
        p1 = p1->next;
        cycle_num++;
    }

    p1 = p2 = head;
    while (p1)
    {
        for (int i = 0; i < cycle_num; i++)
            p2 = p2->next;

        if (p2 == p1)
            return p2;
        p1 = p1->next;
        p2 = p1;
    }

    return nullptr;
}

TEST_F (Test, test1)
{
    list_->addAtHead(3);
    list_->addAtTail(2);
    list_->addAtTail(0);
    list_->addAtTail(-4);
    
    ASSERT_EQ(std::vector<int>({3,2,0,-4}), list_->getVector());

    list_->getNode(3)->next = list_->getNode(1);

    ASSERT_TRUE(hasCycle(list_));

    ASSERT_EQ(detectCycle(list_), list_->getNode(1));
}

TEST_F (Test, test2)
{
    list_->addAtHead(1);
    list_->addAtTail(2);

    ASSERT_EQ(std::vector<int>({1,2}), list_->getVector());

    list_->getNode(1)->next = list_->getNode(0);

    ASSERT_TRUE(hasCycle(list_));

    ASSERT_EQ(detectCycle(list_), list_->getNode(0));
}

TEST_F (Test, test3)
{
    list_->addAtHead(1);

    ASSERT_EQ(std::vector<int>({1}), list_->getVector());

    ASSERT_FALSE(hasCycle(list_));

    ASSERT_EQ(detectCycle(list_), nullptr);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}