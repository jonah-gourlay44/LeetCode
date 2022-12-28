#include "list_node.h"
#include <gtest/gtest.h>

class Test : public ::testing::Test
{
public:
    void SetUp() override
    {
        listA_ = new ListNode();
        listB_ = new ListNode();
    }

    void TearDown() override
    {
        delete listA_;
        delete listB_;
    }

protected:
    ListNode *listA_;
    ListNode *listB_;
};

bool hasIntersection(ListNode *headA, ListNode *headB, int& lengthA, int& lengthB)
{
    if (!headA || !headB)
        return false;

    ListNode *pA, *pB;
    pA = headA;
    pB = headB;

    lengthA = lengthB = 1;
    while (pA->next)
    {
        pA = pA->next;
        lengthA++;
    }
    while (pB->next)
    {
        pB = pB->next;
        lengthB++;
    }

    if (pB == pA)
        return true;

    return false;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lengthA, lengthB;
    if (!hasIntersection(headA, headB, lengthA, lengthB))
        return nullptr;

    int diff = abs(lengthA - lengthB);
    ListNode *pA, *pB;
    pA = headA;
    pB = headB;

    if (lengthA > lengthB)
    {
        for (int i = 0; i < diff; ++i)
            pA = pA->next;
    } else {
        for (int i = 0; i < diff; ++i)
            pB = pB->next;
    }

    while (pA && pB)
    {
        if (pA == pB)
            return pA;
        pA = pA->next;
        pB = pB->next;
    }

    return nullptr;
}

TEST_F (Test, test1)
{
    listA_->addAtHead(4);
    listA_->addAtTail(1);
    listA_->addAtTail(8);
    listA_->addAtTail(4);
    listA_->addAtTail(5);

    listB_->addAtHead(5);
    listB_->addAtTail(6);
    listB_->addAtTail(1);
    listB_->getNode(2)->next = listA_->getNode(2);

    int lengthA, lengthB;
    ASSERT_TRUE(hasIntersection(listA_, listB_, lengthA, lengthB));

    ASSERT_EQ(lengthA, 5);
    ASSERT_EQ(lengthB, 6);

    ASSERT_EQ(getIntersectionNode(listA_, listB_), listA_->getNode(2));
}

TEST_F (Test, test2)
{
    listA_->addAtHead(2);
    listA_->addAtTail(6);
    listA_->addAtTail(4);

    listB_->addAtHead(1);
    listB_->addAtTail(5);

    int lengthA, lengthB;
    ASSERT_FALSE(hasIntersection(listA_, listB_, lengthA, lengthB));

    ASSERT_EQ(lengthA, 3);
    ASSERT_EQ(lengthB, 2);

    ASSERT_EQ(getIntersectionNode(listA_, listB_), nullptr);
}

TEST_F (Test, test3)
{
    listA_->addAtHead(1);
    listA_->addAtTail(9);
    listA_->addAtTail(1);
    listA_->addAtTail(2);
    listA_->addAtTail(4);

    listB_->addAtHead(3);
    listB_->getNode(0)->next = listA_->getNode(3);

    int lengthA, lengthB;
    ASSERT_TRUE(hasIntersection(listA_, listB_, lengthA, lengthB));

    ASSERT_EQ(lengthA, 5);
    ASSERT_EQ(lengthB, 3);

    ASSERT_EQ(getIntersectionNode(listA_, listB_), listA_->getNode(3));
}

int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

