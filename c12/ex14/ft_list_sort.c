/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:33:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/07 19:13:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	void	*data_temp;
	t_list	*list_ptr;
	t_list	*other_list_ptr;

	list_ptr = *begin_list;
	while (list_ptr->next)
	{
		other_list_ptr = list_ptr->next;
		if ((*cmp)(list_ptr->data, other_list_ptr->data) > 0)
		{
			data_temp = list_ptr->data;
			list_ptr->data = other_list_ptr->data;
			other_list_ptr->data = data_temp;
			list_ptr = *begin_list;
		}
		else
			list_ptr = list_ptr->next;
	}
}
