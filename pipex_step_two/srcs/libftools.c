/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:41:20 by faventur          #+#    #+#             */
/*   Updated: 2022/07/20 14:35:46 by faventur         ###   ########.fr       */
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

	if (!str)
		return (0);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (-3000);
	i = 0;
	if (n <= 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1
		&& ((unsigned char *)s1)[i] != '\0' && ((unsigned char *)s2)[i] != '\0')
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_strstrbool(const char *haystack, const char *needle)
{
	t_cmp	var;

	if (!haystack || !needle)
		return (0);
	var.str_len = ft_strlen(haystack);
	var.tofind_len = ft_strlen(needle);
	var.i = 0;
	if (var.str_len < var.tofind_len)
		return (1);
	while (var.i <= var.str_len - var.tofind_len)
	{
		var.j = 0;
		while (var.j < var.tofind_len)
		{
			if (*(char *)(haystack + var.i + var.j)
				!= *(char *)(needle + var.j))
				break ;
			var.j++;
		}
		if (var.j == var.tofind_len)
			return (0);
		var.i++;
	}
	return (1);
}
