/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:07:30 by faventur          #+#    #+#             */
/*   Updated: 2022/06/08 09:23:33 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putendl_fd(char *str, int fd)
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

void	ft_puterror(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}
