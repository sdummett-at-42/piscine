/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 20:59:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/08 10:24:13 by sdummett         ###   ########.fr       */
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
	t_list	*tmp;
	t_list	*list_ptr;
	t_list	*other_list_ptr;
	t_list	*previous_list_ptr;

	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		list_ptr = *begin_list1;
		other_list_ptr = begin_list2;
		while (list_ptr && other_list_ptr)
		{
			if ((*cmp)(list_ptr->data, other_list_ptr->data) >= 0)
			{
				if (list_ptr == *begin_list1)
				{
					*begin_list1 = other_list_ptr;
					other_list_ptr = other_list_ptr->next;
					tmp = *begin_list1;
					tmp->next = list_ptr;
				}
				else
				{
					previous_list_ptr->next = other_list_ptr;
					other_list_ptr = other_list_ptr->next;
					previous_list_ptr->next->next = list_ptr;
				}
			}
			previous_list_ptr = list_ptr;
			list_ptr = list_ptr->next;
		}
		if (other_list_ptr)
			previous_list_ptr->next = other_list_ptr;
	}
}
