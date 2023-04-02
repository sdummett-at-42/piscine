/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:33:33 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/07 18:14:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*previous;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		if (!(*cmp)(list_ptr->data, data_ref))
		{
			(free_fct)(list_ptr->data);
			if (list_ptr == *begin_list)
				*begin_list = list_ptr->next;
			else
				previous->next = list_ptr->next;
			free(list_ptr);
			list_ptr = *begin_list;
		}
		previous = list_ptr;
		list_ptr = list_ptr->next;
	}
}
