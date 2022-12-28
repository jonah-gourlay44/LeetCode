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
    ListNode* cur = head;
    ListNode* prev = nullptr;

    auto deleteNode = [&head](ListNode* node, ListNode* prev)
    {
        if (prev)
            prev->next = node->next;
        else
            head = node->next;

        //delete node;
    };

    while (cur)
    {
        if (cur->val == val)
        {
            ListNode* temp = cur->next;
            deleteNode(cur, prev);
            cur = temp;
            continue;
        }

        prev = cur;
        cur = cur->next;
    }

    return head;
}

TEST_F(Test, test1)
{
    list_->addAtHead(1);
    list_->addAtTail(2);
    list_->addAtTail(6);
    list_->addAtTail(3);
    list_->addAtTail(4);
    list_->addAtTail(5);
    list_->addAtTail(6);

    removeElements(list_, 6);

    EXPECT_EQ(list_->getVector(), std::vector<int>({1,2,3,4,5}));
}

TEST_F(Test, test2)
{
    removeElements(list_, 1);

    EXPECT_EQ(list_->getVector(), std::vector<int>({}));
}

TEST_F(Test, test3)
{
    list_->addAtHead(7);
    list_->addAtTail(7);
    list_->addAtTail(7);
    list_->addAtTail(7);

    removeElements(list_, 7);

    EXPECT_EQ(list_->getVector(), std::vector<int>({}));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}