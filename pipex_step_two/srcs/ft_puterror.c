/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:07:30 by faventur          #+#    #+#             */
/*   Updated: 2022/06/10 13:06:51 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_putendl_fd(const char *str, int fd)
{
	if (fd >= 0 && str)
	{
		while (*str)
		{
			write(fd, &*str, 1);
			str++;
		}
		write(1, "\n", 1);
	}
}

static void	ft_putstr_fd(const char *str, int fd)
{
	if (fd >= 0 && str)
	{
		while (*str)
		{
			write(fd, &*str, 1);
			str++;
		}
	}
}

void	ft_puterror(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	print_enoent(char *pathname)
{
	ft_putstr_fd("ft_cat: ", 2);
	ft_putstr_fd(pathname, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(ENOENT), 2);
}
