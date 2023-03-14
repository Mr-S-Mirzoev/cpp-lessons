#include "small_test_framework.h"
#include "linked_list.h"

TEST_MAIN_BEGIN()
{
UNIT_TEST_BEGIN(LinkedList, ll_utils)
{
    LinkedListNode *head1 = new LinkedListNode({nullptr, 5});
    head1->next = new LinkedListNode({nullptr, -2});
    LinkedListNode *head2 = new LinkedListNode({nullptr, 3});
    head2->next = new LinkedListNode({nullptr, 4});
    head2->next->next = new LinkedListNode({nullptr, 5});

    EXPECT_FALSE(head1 == nullptr);
    EXPECT_FALSE(head2 == nullptr);
    EXPECT_FALSE(check_sorted(head1));
    EXPECT_TRUE(check_sorted(head2));
    EXPECT_TRUE(check_sorted(nullptr));
    EXPECT_EQ(get_size(head1), 2);
    EXPECT_EQ(get_size(head2), 3);
    EXPECT_EQ(get_size(nullptr), 0);

    print_list(head1);
    print_list(head2);
}
UNIT_TEST_END(LinkedList, ll_utils)

UNIT_TEST_BEGIN(LinkedList, simple)
{
    LinkedListNode *head1 = new LinkedListNode({nullptr, 5});
    LinkedListNode *head2 = new LinkedListNode({nullptr, 3});

    LinkedListNode *head = merge(head1, head2);

    EXPECT_FALSE(head == nullptr);
    EXPECT_TRUE(check_sorted(head));
    EXPECT_EQ(get_size(head), 2);

    print_list(head);
}
UNIT_TEST_END(LinkedList, simple)

UNIT_TEST_BEGIN(LinkedList, two_lists)
{
    LinkedListNode *head1 = new LinkedListNode({nullptr, 5});
    head1->next = new LinkedListNode({nullptr, 8});
    LinkedListNode *head2 = new LinkedListNode({nullptr, -2});
    head2->next = new LinkedListNode({nullptr, 4});
    head2->next->next = new LinkedListNode({nullptr, 5});

    LinkedListNode *head = merge(head1, head2);

    EXPECT_FALSE(head == nullptr);
    EXPECT_TRUE(check_sorted(head));
    EXPECT_EQ(get_size(head), 5);

    print_list(head);
}
UNIT_TEST_END(LinkedList, two_lists)

UNIT_TEST_BEGIN(LinkedList, one_empty)
{
    LinkedListNode *head1 = nullptr;
    LinkedListNode *head2 = new LinkedListNode({nullptr, -2});
    head2->next = new LinkedListNode({nullptr, 4});
    head2->next->next = new LinkedListNode({nullptr, 5});

    LinkedListNode *head = merge(head1, head2);

    EXPECT_FALSE(head == nullptr);
    EXPECT_TRUE(check_sorted(head));
    EXPECT_EQ(get_size(head), 3);

    print_list(head);
}
UNIT_TEST_END(LinkedList, one_empty)
}
TEST_MAIN_END()