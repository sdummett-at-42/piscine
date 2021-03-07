/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:17:25 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/07 19:44:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	i;
	int	j;
	void	*data_temp;
	t_list	*list_ptr;

	i = 0;
	list_ptr = begin_list;
	while (list_ptr->next)
	{
		list_ptr = list_ptr->next;
		i++;
	}
	list_ptr = begin_list;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			data_temp = list_ptr->data;
			list_ptr->data = list_ptr->next->data;
			list_ptr->next->data = data_temp;
			list_ptr = list_ptr->next;
			j++;
		}
		list_ptr = begin_list;
		i--;
	}
}
