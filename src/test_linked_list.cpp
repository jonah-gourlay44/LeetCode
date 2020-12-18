#include <iostream>
#include <gtest/gtest.h>
#include "impl/list_node.hpp"

class TestLinkedList : public ::testing::Test
{
public:
    void SetUp() override
    {
        obj = new ListNode();
    }

    void TearDown() override
    {
        delete obj;
    }

protected:
    ListNode * obj;
};

TEST_F(TestLinkedList, test1)
{
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);

    ASSERT_EQ(std::vector<int>({1,2,3}), obj->getVector());

    ASSERT_EQ(2, obj->get(1));

    obj->deleteAtIndex(1);

    ASSERT_EQ(3, obj->get(1));
}

TEST_F(TestLinkedList, test2)
{
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);

    ASSERT_EQ(std::vector<int>({1,2,7}), obj->getVector());

    obj->addAtIndex(3,0);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);

    ASSERT_EQ(std::vector<int>({6,1,2,0,4}), obj->getVector());

    ASSERT_EQ(4, obj->get(4));

    obj->addAtHead(4);
    obj->addAtIndex(5,0);
    obj->addAtHead(6);

    ASSERT_EQ(std::vector<int>({6,4,6,1,2,0,0,4}), obj->getVector());
}

TEST_F(TestLinkedList, test3)
{
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);

    ASSERT_EQ(2, obj->get(1));

    obj->deleteAtIndex(1);

    ASSERT_EQ(3, obj->get(1));
}

TEST_F(TestLinkedList, test4)
{
    obj->addAtIndex(0, 10);
    obj->addAtIndex(0, 20);
    obj->addAtIndex(1, 30);

    ASSERT_EQ(20, obj->get(0));
    ASSERT_EQ(std::vector<int>({20,30,10}), obj->getVector());
}

TEST_F(TestLinkedList, test5)
{
    obj->addAtHead(2);
    obj->deleteAtIndex(1);
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);

    ASSERT_EQ(2, obj->get(5));

    obj->deleteAtIndex(6);
    obj->deleteAtIndex(4);

    ASSERT_EQ(std::vector<int>({5,2,3,7,2}), obj->getVector());
}

TEST_F(TestLinkedList, test6)
{
    obj->addAtHead(0);
    obj->addAtIndex(1,4);
    obj->addAtTail(8);
    obj->addAtHead(5);
    obj->addAtIndex(4,3);
    obj->addAtTail(0);
    obj->addAtTail(5);
    obj->addAtIndex(6,3);
    obj->deleteAtIndex(7);
    obj->deleteAtIndex(5);
    obj->addAtTail(4);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}