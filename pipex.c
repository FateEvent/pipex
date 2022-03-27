/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/03/27 16:30:42 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	buffer[MAX_SIZE];

	i = 0;
	(void) argv;
	if (argc == 3)
	{
		open_and_read(buffer, argv[1]);
		char	**args = {buffer, NULL};
		execve(argv[1], args, NULL);
		return (0);
	}
	/*
	while (i++ < argc)
	{
		if (operand_checker(argv[i]) == 1)
		{
			open_and_write(buffer, argc, argv, i);
			return (0);
		}
		else if (operand_checker(argv[i]) == 2)
		{
			open_and_append(buffer, argc, argv, i);
			return (0);
		}
	}
	write(1, &buffer, ft_strlen(buffer));
	return (0);
	*/
}
