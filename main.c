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

#include "./libft/libft.a"

void	ft_cmd_exec(int fd, char *cmd, char *paths, char *envp[])
{
	char	**exec_args;
	char	*cmd_path;
	int		i;

	i = 0;
	exec_args = ft_split(cmd, " ");
	while (paths[i++])
	{
		cmd_path = ft_join(paths[i], cmd);
		execve(cmd_path, exec_args, envp);
		perror("La cata!");
		free(command);
	}
	return (EXIT_FAILURE);
}

void	ft_parser(char *argv[], char *envp[], char **paths, char *env_path)
{
	int		i;

	i = 0;
	while (envp[i++])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			env_path = ft_strnstr(envp[i], "PATH", 4);
	}
	paths = ft_split(env_path, ":");
}

void	parent_process(int fd2, char *cmd2, int end[2])
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(fd2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(fd2);
	ft_cmd_exec(fd2, argv[3], argv, envp);
	exit(EXIT_FAILURE);
}

void	child_process(int fd1, char *cmd1, int end[2])
{
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(fd1);
	ft_cmd_exec(fd1, argv[2], argv, envp);
	exit(EXIT_FAILURE);
}

void	pipex(int fd1, int fd2, char *argv[], char *envp[])
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
		child_process(fd1, argv[2], end);
	child = fork();
	if (child < 0)
		perror("Fork: ");
	if (child == 0)
		parent_process(fd2, argv[3], end);
	close(end[0]);
	close(end[1]);
	waitpid(parent, &status, 0);
	waitpid(child, &status, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd1;
	int		fd2;
	char	**paths;
	char	*env_path;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		return (-1);
	ft_parser(argv, envp, paths, env_path);
	pipex(fd1, fd2, argv, envp);
	return (0);
}

https://github.com/tolmvad/pipex/tree/master/mandatory
