/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:22:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/06 12:01:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_list.h"
#include <stdio.h>
t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **strs)
{
	int	i;
	t_list	*lst;
	t_list	*curr;

	if (size == 0)
		return (0);
	lst = ft_create_elem(strs[0]);
	curr = lst;
	i = 1;
	while (i < size)
	{
		curr->next = ft_create_elem(strs[i]);
		curr = curr->next;
		i++;
	}
	return (lst);
}	
