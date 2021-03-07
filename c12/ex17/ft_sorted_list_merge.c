/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:59:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/07 21:32:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"
#include <stdio.h>
#include <stdlib.h>
void	ft_list_push_back(t_list **begin_list, void *data);

int	comp(int *a, int *b)
{
	return (*a - *b);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*other_list_ptr;

	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		list_ptr = *begin_list1;
		other_list_ptr = *begin_list2;
		while (list_ptr && other_list_ptr)
		{
			if ((*cmp)(list_ptr->data, other_list_ptr->data) >= 0)
			{
				if (list_ptr == *begin_list1)
					begin_list = other_list_ptr;
				else
					previous_list_ptr->next = other_list_ptr;
				other_list_ptr = other_list_ptr->next;
				/////////////////////////
			}
		}
	}
}

int	main()
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*curr;
	int	*tab;
	int	*tab2;
	int	i;

	if (!(tab = malloc(sizeof(int) * 10)))
		return (0);
	if (!(tab2 = malloc(sizeof(int) * 10)))
		return (0);
	i = 0;
	while (i < 10)
	{
		*(tab + i) = i;
		ft_list_push_back(&lst, (tab + i));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		*(tab2 + i) = i;
		ft_list_push_back(&lst2, (tab2 + i));
		i++;
	}
	printf("		>>>BEFORE MERGING && SORTING<<<\n");
	curr = lst;
	while (curr)
	{
		printf("lst->data %d\n", *(int *)curr->data);
		curr = curr->next;
	}
	curr = lst2;
	while (curr)
	{
		printf("lst2->data %d\n", *(int *)curr->data);
		curr = curr->next;
	}

	printf("		>>>AFTER MERGING && SORTING<<<\n");
	curr = lst;
	while (curr)
	{
		printf("lst->data %d\n", *(int *)curr->data);
		curr = curr->next;
	}
	curr = lst2;
	while (curr)
	{
		printf("lst2->data %d\n", *(int *)curr->data);
		curr = curr->next;
	}
	return (0);
}
