/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:32:07 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/17 19:33:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
#define FT_HEADER_H

#include <string.h>

#include <unistd.h>

#include <errno.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 25000

int	ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putbuf(char *str, int ret);

#endif
