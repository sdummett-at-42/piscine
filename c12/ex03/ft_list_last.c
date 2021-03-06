/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:12:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/06 09:56:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list)
	{
		if (!(begin_list->next))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (begin_list);
}
