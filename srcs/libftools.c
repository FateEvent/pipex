/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:41:20 by faventur          #+#    #+#             */
/*   Updated: 2022/05/14 09:43:57 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
	else
		return ;
}

void	ft_putstr_fd(char const *str, int fd)
{
	if (fd >= 0 && str)
	{
		while (*str != '\0')
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (fd >= 0)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		counter++;
		str++;
	}
	return (counter);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && !needle[0])
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle) || len < ft_strlen(needle))
		return (NULL);
	while (i <= ft_strlen(haystack) - ft_strlen(needle) && i < len)
	{
		j = 0;
		while (j < ft_strlen(needle) && i + j < len)
		{
			if (*(char *)(haystack + i + j) != *(char *)(needle + j))
				break ;
			j++;
		}
		if (j == ft_strlen(needle))
			return (&*(char *)(haystack + i));
		i++;
	}
	return (NULL);
}
