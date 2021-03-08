#include "../ft_list.h"
#include <stdlib.h>
t_list *head;

t_list    *create_list(void *data)
{
    t_list *new_list;

    if(!(new_list = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    new_list->data = data;
    new_list->next = NULL;
    return (new_list);
}

void    push_data(void *data)
{
    t_list *new_list;

    new_list = create_list(data);
    new_list->next = head;
    head = new_list;
}

void    add_ten(void *data)
{
    *(int *)data += 10;
}

int        compare(void *a, void *b)
{
    if (((*(int *)a) - (*(int *)b)) == 0)
        return (0);
    return (1);
}

#include <stdio.h>


int main(void)
{
    int arr[4] = {1, 0, 1, 3};
    push_data(&arr[3]);
    push_data(&arr[2]);
    push_data(&arr[1]);
    push_data(&arr[0]);
    t_list *cpy;

    cpy = head;
    while (cpy)
    {
        printf("%d", *(int *)cpy->data);
        cpy = cpy->next;
        printf("\n");
    }
    ft_list_remove_if(&head, &arr[0], &compare);
    while (head)
    {
        printf("%d", *(int *)head->data);
        head = head->next;
        printf("\n");
    }
}
