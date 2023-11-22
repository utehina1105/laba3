#include "TQueue.h"

#include <gtest.h>

TEST(TQueue, can_create_stack_with_positive_length)//+

{
	ASSERT_NO_THROW(TQueue<int> sk(3));
}

TEST(TQueue, create_empty_stack)//+
{
	TQueue<int> st(3);

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TQueue, create_empty_size)//+
{
	EXPECT_ANY_THROW(TQueue<int> st(0););
}

TEST(TQueue, cant_Pull_if_full)//+
{
	TQueue<int> st(1);

	EXPECT_ANY_THROW(st.Push(1); st.Push(2););
}

TEST(TQueue, can_Pull_if_ok)
{
	TQueue<int> st(5);
	st.Push(3);
	st.Push(4);
	EXPECT_NO_THROW(st.Pull(););
}

TEST(TQueue, cant_get_with_no_mem)//+
{
	EXPECT_ANY_THROW(TQueue<int> st(0); st.Push(2););
}

TEST(TQueue, cant_get_if_empty)
{
	EXPECT_ANY_THROW(TQueue<int> st(0); st.GetCoun(););
}

TEST(TQueue, can_get_true_value)
{
	TQueue<int> st(3);

	st.Push(3);
	EXPECT_EQ(1, st.GetCoun());
}

TEST(TQueue, empty_stack_after_get_first_element)
{
	TQueue<int> st(2);

	st.Push(5);
	st.Pull();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TQueue, cant_Pull_when_no_mem)//+
{
	EXPECT_ANY_THROW(TQueue<int> st(0); st.Pull(););
}

TEST(TQueue, cant_Pull_if_empty)//+
{
	EXPECT_ANY_THROW(TQueue<int> st(5);	st.Pull(););
}

TEST(TQueue, can_Pull)//+
{
	ASSERT_NO_THROW(TQueue<int> st(3);	st.Push(9); st.Pull(););
}

TEST(TQueue, can_Pull_true_value)
{
	TQueue<int> st(3);
	int n = 4;
	st.Push(n);
	EXPECT_EQ(n, st.Pull());
}
