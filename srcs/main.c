/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/06/08 12:23:14 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_var	get_args(char ac, char *av[], char *envp[])
{
	t_var	var;

	var.fd[0] = open(av[1], O_RDONLY);
	if (var.fd[0] < 0)
		ft_puterror("Error: Impossible to open the file.");
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var.fd[0] < 0)
		ft_puterror("Error: Impossible to open the file.");
	var.cmd_args1 = ft_split(av[2], ' ');
	var.cmd1 = ft_path_searcher(var.cmd_args1[0], envp);
	if (!var.cmd_args1)
		ft_puterror("Error: Impossible to find the binary file.");
	var.cmd_args2 = ft_split(av[3], ' ');
	var.cmd2 = ft_path_searcher(var.cmd_args2[0], envp);
	if (!var.cmd_args2)
		ft_puterror("Error: Impossible to find the binary file.");
	return (var);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;

	if (argc < 5)
		ft_puterror("Error: The number of arguments is incorrect.");
	var = get_args(argc, argv, envp);
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	dup2(var.fd[1], STDOUT_FILENO);
	close(var.fd[1]);
	var.pid[0] = fork();
	if (var.pid[0] < 0)
		ft_puterror("Error: Failed to create the fork.");
	if (var.pid[0] == 0)
		pipex(var);
	waitpid(-1, &var.status, 0);
	return (0);
}
