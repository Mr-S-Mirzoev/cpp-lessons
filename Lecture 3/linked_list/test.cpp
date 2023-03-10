#include "small_test_framework.h"
#include "linked_list.h"

TEST_MAIN_BEGIN()
{
UNIT_TEST_BEGIN(LinkedList, simple)
{
    LinkedListNode *head1 = new LinkedListNode({nullptr, 5});
    LinkedListNode *head2 = new LinkedListNode({nullptr, 3});

    LinkedListNode *head = merge(head1, head2);

    ASSERT_FALSE(head == nullptr);
    ASSERT_TRUE(check_sorted(head));
    ASSERT_EQ(get_size(head), 2);

    print_list(head);

    return 0;
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

    ASSERT_FALSE(head == nullptr);
    ASSERT_TRUE(check_sorted(head));
    ASSERT_EQ(get_size(head), 5);

    print_list(head);

    return 0;
}
UNIT_TEST_END(LinkedList, two_lists)
}
TEST_MAIN_END()