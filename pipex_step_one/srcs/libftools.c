/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:41:20 by faventur          #+#    #+#             */
/*   Updated: 2022/06/10 11:59:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_arr_freer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
