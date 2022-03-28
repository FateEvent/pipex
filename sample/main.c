/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:35:05 by faventur          #+#    #+#             */
/*   Updated: 2022/03/28 18:59:59 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void	ft_exec(char *cmd1, char *cmd2, char *envp[])
{
	char	*env_path;
	char	*paths;
	char	*cmd_args;
	int		i;

	i = 0;
	env_path = envp[3];
	paths = ft_strjoin(paths, ":");
	cmd_args = 
	execve
}

void	parent_process(int fd2, char *cmd2, int end[2])
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(fd2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(fd2);
	// execve function for each possible path (see below)
	exit(EXIT_FAILURE);
}

void	child_process(int fd1, char *cmd1, int end[2])
{
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(fd1);
	// execve function for each possible path (see below)
	exit(EXIT_FAILURE);
}

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2)
{
	int		end[2];
	int		status;
	pid_t	parent;
	pid_t	child;

	pipe(end);
	parent = fork();
	if (parent < 0)
		perror("Fork: ");
	if (parent == 0)
		child_process(fd1, cmd1, end);
	child = fork();
	if (child < 0)
		perror("Fork: ");
	if (child == 0)
		parent_process(fd2, cmd2, end);
	close(end[0]);         // this is the parent
	close(end[1]);         // doing nothing
	waitpid(parent, &status, 0);  // supervising the children
	waitpid(child, &status, 0);  // while they finish their tasks
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		return (-1);
	pipex(fd1, fd2, argv[2], argv[3]);
	return (0);
}
