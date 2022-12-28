#include <gtest/gtest.h>
#include "hash_map.h"

class TestHashMap : public ::testing::Test 
{
public:
    void SetUp() override
    {
        obj = new HashMap();
    }

    void TearDown() override
    {
        delete obj;
    }

protected:
    HashMap * obj;
};

TEST_F(TestHashMap, test1)
{
    obj->put(1,1);
    obj->put(2,2);

    ASSERT_EQ(obj->get(1), 1);
    ASSERT_EQ(obj->get(3), -1);

    obj->put(2,1);

    ASSERT_EQ(obj->get(2), 1);

    obj->remove(2);

    ASSERT_EQ(obj->get(2), -1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}