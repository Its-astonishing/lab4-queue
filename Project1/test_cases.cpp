#include <gtest.h>
#include "queue.h"
TEST(queue, can_create_queue)
{
    ASSERT_NO_THROW(queue<int> bf(10));
}
TEST(queue, cant_create_queue_with_negative_size)
{
    ASSERT_ANY_THROW(queue<int> bf(-10));
}
TEST(queue, cant_create_queue_with_too_large_size)
{
    ASSERT_ANY_THROW(queue<int> bf(1000000));
}
TEST(queue, can_push_back)
{
    queue<int> bf(2);
    ASSERT_NO_THROW(bf.push_back(10));
}
TEST(queue, can_pop)
{
    queue<int> bf(2);
    bf.push_back(10);
    EXPECT_EQ(10, bf.pop());
}
TEST(queue, cant_push_back_into_full_queue)
{
    queue<int> bf(1);
    bf.push_back(10);
    EXPECT_ANY_THROW(bf.push_back(100));
}
TEST(queue, cant_pop_into_empty_queue)
{
    queue<int> bf(1);
    EXPECT_ANY_THROW(bf.pop());
}
TEST(queue, can_get_size)
{
    queue<int> bf(1);
    EXPECT_EQ(1, bf.getSize());
}
TEST(queue, isFull_is_correct)
{
    queue<int> bf(1);
    bf.push_back(0);
    EXPECT_TRUE(bf.isFull());
}
TEST(queue, isEmpty_is_correct)
{
    queue<int> bf(1);
    EXPECT_TRUE(bf.isEmpty());
}
