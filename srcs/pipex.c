/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:18:24 by faventur          #+#    #+#             */
/*   Updated: 2022/06/08 12:23:28 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
static void ft_execute()
{
	
}
*/
static void	parent_process(t_var var)
{
	close(var.end[1]);
	dup2(var.end[0], STDIN_FILENO);
	close(var.end[0]);
	waitpid(-1, &var.status, 0);
	waitpid(-1, &var.status, 0);
	execve(var.cmd2, var.cmd_args2, NULL);
	exit(EXIT_FAILURE);
}

static void	child_process(t_var var)
{
	close(var.end[0]);
	dup2(var.end[1], STDOUT_FILENO);
	close(var.end[1]);
	execve(var.cmd1, var.cmd_args1, NULL);
	exit(EXIT_FAILURE);
}

void	pipex(t_var var)
{
	if (pipe(var.end) == -1)
		ft_puterror("Error: Failed to create the pipe.");
	var.pid[1] = fork();
	if (var.pid[1] < 0)
	{
		close(var.end[0]);
		close(var.end[1]);
		ft_puterror("Error: Failed to create the fork.");
	}
	if (var.pid[1] == 0)
		child_process(var);
	parent_process(var);
}
