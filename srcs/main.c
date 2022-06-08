/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/06/08 09:05:35 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_var var)
{
	close(var.end[1]);
	dup2(var.end[0], STDIN_FILENO);
	dup2(var.fd[1], STDOUT_FILENO);
	close(var.fd[1]);
	close(var.end[0]);
	waitpid(-1, &var.status, 0);
	waitpid(-1, &var.status, 0);
	execve(var.cmd2, var.cmd_args2, NULL);
	exit(EXIT_FAILURE);
}

void	child_process(t_var var)
{
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	close(var.end[1]);
	execve(var.cmd1, var.cmd_args1, NULL);
	exit(EXIT_FAILURE);
}

t_var	get_args(char *av[], char *envp[])
{
	t_var	var;

	var.fd[0] = open(av[1], O_RDONLY);
	var.fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	var.cmd_args1 = ft_split(av[2], ' ');
	var.cmd1 = ft_path_searcher(var.cmd_args1[0], envp);
	var.cmd_args2 = ft_split(av[3], ' ');
	var.cmd2 = ft_path_searcher(var.cmd_args2[0], envp);
	return (var);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;

	(void)argc;	// check_args
	var = get_args(argv, envp);
	var.pid[0] = fork();
	if (var.pid[0] < 0)
		return (2);
	if (var.pid[0] == 0)
	{
		if (pipe(var.end) == -1)
			return (1);
		var.pid[1] = fork();
		if (var.pid[1] < 0)
		{
			close(var.end[0]);
			close(var.end[1]);
			return (2);
		}
		if (var.pid[1] == 0)
			child_process(var);
		parent_process(var);
	}
	waitpid(-1, &var.status, 0);
	return (0);
}
