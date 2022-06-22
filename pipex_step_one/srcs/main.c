/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/06/22 16:21:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(t_var var)
{
	dup2(var.fd[1], STDOUT_FILENO);
	close(var.fd[1]);
	close(var.end[1]);
	dup2(var.end[0], STDIN_FILENO);
	close(var.end[0]);
	waitpid(-1, &var.status, 0);
	execve(var.cmd2, var.cmd_args2, NULL);
	ft_puterror("Error: Couldn't be able to process your request.");
}

static void	child_process(t_var var)
{
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	close(var.end[1]);
	execve(var.cmd1, var.cmd_args1, NULL);
	ft_puterror("Error: Couldn't be able to process your request.");
}

t_var	get_args(char *av[], char *envp[])
{
	t_var	var;

	var.fd[0] = open(av[1], O_RDONLY);
	if (var.fd[0] < 0)
		ft_puterror("Error: Impossible to open the file.");
	var.fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var.fd[1] < 0)
		ft_puterror("Error: Impossible to open the file.");
	var.cmd_args1 = ft_split(av[2], ' ');
	var.cmd1 = ft_path_searcher(var.cmd_args1[0], envp);
	if (!var.cmd1)
		ft_puterror("Error: Impossible to find the binary file.");
	var.cmd_args2 = ft_split(av[3], ' ');
	var.cmd2 = ft_path_searcher(var.cmd_args2[0], envp);
	if (!var.cmd2)
		ft_puterror("Error: Impossible to find the binary file.");
	return (var);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;

	if (argc != 5)
		ft_puterror("Error: The number of arguments is incorrect.");
	var = get_args(argv, envp);
	if (pipe(var.end) == -1)
		ft_puterror("Error: Failed to create the pipe.");
	var.pid = fork();
	if (var.pid < 0)
	{
		close(var.end[0]);
		close(var.end[1]);
		ft_puterror("Error: Failed to create the fork.");
	}
	if (var.pid == 0)
		child_process(var);
	parent_process(var);
	return (0);
}
