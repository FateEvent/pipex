/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/06/09 12:16:43 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec(char *cmd, char *env[])
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	cmd = ft_path_searcher(cmd_args[0], env);
	if (!cmd)
		ft_puterror("Error: Impossible to find the binary file.");
	execve(cmd, cmd_args, NULL);
}

static void	parent_process(t_var var, char *cmd, char *env[])
{
	close(var.end[1]);
	dup2(var.end[0], STDIN_FILENO);
	close(var.end[0]);
	waitpid(-1, &var.status, 0);
	waitpid(-1, &var.status, 0);
	ft_exec(cmd, env);
	exit(EXIT_FAILURE);
}

static void	child_process(t_var var, char *cmd, char *env[], int fdin)
{
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	close(var.end[1]);
	if (fdin == STDIN_FILENO)
		exit(1);
	ft_exec(cmd, env);
	exit(EXIT_FAILURE);
}

void	pipex(char *cmd, char *env[], int fdin)
{
	pid_t	pid;
	t_var	var;

	if (pipe(var.end) == -1)
		ft_puterror("Error: Failed to create the pipe.");
	pid = fork();
	if (pid < 0)
	{
		close(var.end[0]);
		close(var.end[1]);
		ft_puterror("Error: Failed to create the fork.");
	}
	if (pid == 0)
		child_process(var, cmd, env, fdin);
	parent_process(var, cmd, env);
}
