/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:07:30 by faventur          #+#    #+#             */
/*   Updated: 2022/06/10 15:15:46 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_puterror() and the ft_printerror() functions send an error
** message.
**
** The ft_printerror() function takes the program and the command name
** as parameter and sends an error message via STRERROR(3) and errno
** (see INTRO(2)). It needs therefore access to the <string.h> and
** <errno.h> libraries.
*/

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

void	ft_puterror(const char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	ft_printerror(char *program, char *pathname)
{
	ft_printf_fd(2, "%s: %s: %s\n", program, pathname, strerror(errno));
	exit(1);
}
