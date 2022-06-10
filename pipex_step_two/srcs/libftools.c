/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:41:20 by faventur          #+#    #+#             */
/*   Updated: 2022/06/10 12:16:43 by faventur         ###   ########.fr       */
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

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

int	ft_strstrbool(const char *haystack, const char *needle)
{
	size_t	str_len;
	size_t	tofind_len;
	size_t	i;
	size_t	j;

	str_len = ft_strlen(haystack);
	tofind_len = ft_strlen(needle);
	i = 0;
	if (str_len < tofind_len)
		return (1);
	while (i <= str_len - tofind_len)
	{
		j = 0;
		while (j < tofind_len)
		{
			if (*(char *)(haystack + i + j) != *(char *)(needle + j))
				break ;
			j++;
		}
		if (j == tofind_len)
			return (0);
		i++;
	}
	return (1);
}
