/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/03/28 13:44:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		fd;
	int		pipe_fd[2];
	int		bytes_read;
	char	buffer[MAX_SIZE];

	i = 0;
	(void) argv;
	if (argc == 3)
	{
		fd = open(argv[0], O_RDONLY);
		if (fd == -1)
			print_error(argv[0], ENOENT);
		if (pipe(fd) == -1)
			print_error("La mauvaise passe", 5);
		bytes_read = read(fd, &buffer, MAX_SIZE);
		if (bytes_read == -1)
			return ;
		close(fd);
		buffer[bytes_read] = '\0';







		/*
		char	**args = {buffer, NULL};
		execve(argv[1], args, envp);
		return (0);
		*/
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
