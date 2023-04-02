/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:02:29 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/07 18:33:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;

	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		list_ptr = *begin_list1;
		while (list_ptr->next)
			list_ptr = list_ptr->next;
		list_ptr->next = begin_list2;
	}
}
