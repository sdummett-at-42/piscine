/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:36:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/18 21:23:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <stdlib.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	ft_strlen(char *str);
void	ft_putstr(char *str);
int	is_minus_c(char *arg);
int	compute_bufsize(char *arg, int i);

#endif
