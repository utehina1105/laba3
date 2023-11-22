#include "TStack.h"

#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)//+

{
	ASSERT_NO_THROW(TStack<int> sk(3));
}

TEST(TStack, create_empty_stack)//+
{
	TStack<int> st(3);

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, create_empty_size)//+
{
	EXPECT_ANY_THROW(TStack<int> st(0););
}

TEST(TStack, cant_Pull_if_full)//+
{
	TStack<int> st(1);

	EXPECT_ANY_THROW(st.Push(1); st.Push(2););
}

TEST(TStack, can_Pull_if_ok)
{
	TStack<int> st(5);	
	st.Push(3);	
	st.Push(4);
	EXPECT_NO_THROW(st.Pull(););
}

TEST(TStack, cant_get_with_no_mem)//+
{
	EXPECT_ANY_THROW(TStack<int> st(0); st.Push(2););
}

TEST(TStack, cant_get_if_empty)
{
	EXPECT_ANY_THROW(TStack<int> st(0);st.GetCount(););
}

TEST(TStack, can_get_true_value)
{
	TStack<int> st(3);

	st.Push(3);
	EXPECT_EQ(1, st.GetCount());
}

TEST(TStack, empty_stack_after_get_first_element)
{
	TStack<int> st(2);

	st.Push(5);
	st.Pull();

	EXPECT_EQ(true, st.IsEmpty());
}

TEST(TStack, cant_Pull_when_no_mem)//+
{
	EXPECT_ANY_THROW(TStack<int> st(0); st.Pull(););
}

TEST(TStack, cant_Pull_if_empty)//+
{
	EXPECT_ANY_THROW(TStack<int> st(5);	st.Pull(););
}

TEST(TStack, can_Pull)//+
{
	ASSERT_NO_THROW(TStack<int> st(3);	st.Push(9); st.Pull(););
}

TEST(TStack, can_Pull_true_value)
{
	TStack<int> st(3);
	int n = 4;
	st.Push(n);
	EXPECT_EQ(n, st.Pull());
}
