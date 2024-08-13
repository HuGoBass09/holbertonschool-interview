#include "lists.h"

/**
 * check_cycle - check whether linked list has a cycle or not
 * @head: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *head)
{
    int n = print_listint(head);
    listint_t *temp_head = head;
    head = head->next;

    for (int i = 0; i <= n; ++i)
    {
        if (head == temp_head)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}