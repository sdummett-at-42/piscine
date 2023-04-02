/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:47:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/08 08:58:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"
t_list	*ft_create_elem(void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*other_list_ptr;
	t_list	*previous_list_ptr;

	other_list_ptr = ft_create_elem(data);
	list_ptr = *begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, other_list_ptr->data) >= 0)
		{
			if (list_ptr == *begin_list)
				*begin_list = other_list_ptr;
			else
				previous_list_ptr->next = other_list_ptr;
			other_list_ptr->next = list_ptr;
			return ;
		}
		else
		{
			previous_list_ptr = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
	previous_list_ptr->next = other_list_ptr;
}
