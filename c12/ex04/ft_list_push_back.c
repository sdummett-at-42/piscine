/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 09:57:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/06 11:22:03 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"
t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*lst;

	if (*begin_list)
	{
		lst = *begin_list;
		while (lst->next)
			lst = lst->next;
		lst->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
