/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/06/06 20:47:36 by faventur         ###   ########.fr       */
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

static char	*find(char *envp[], char *str)
{
	char	*env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], str, 4))
		{
			env_path = envp[i] + 5;
			break ;
		}
		i++;
	}
	return (env_path);
}

char	*path_searcher(char *cmd, char *envp[])
{
	char	**paths;
	char	*exec_path;
	char	*env_path;
	char	**cmd_args;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	env_path = find(envp, "PATH");
	paths = ft_split(env_path, ':');
	while (paths[i])
	{
		exec_path = ft_strjoin(paths[i], ft_strjoin("/", cmd_args[0]));
		if (!access(exec_path, R_OK))
		{
			ft_arr_freer(paths);
			ft_arr_freer(cmd_args);
			return (exec_path);
		}
		i++;
	}
	return (NULL);
}
/*
void	parent_process(char *cmd2, int end[2], char *argv[], char *envp[])
{
	int	status;

	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(end[0]);
	waitpid(-1, &status, 0);
	execve(cmd2, argv, envp);
	exit(EXIT_FAILURE);
}

void	child_process(char *cmd1, int end[2], char *argv[], char *envp[])
{
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(end[1]);
	exit(EXIT_FAILURE);
}

void	pipex(char *argv[], char *envp[])
{
	int		end[2];
	int		status;
	pid_t	parent;
	pid_t	child;
	char	*cmd1;
	char	*cmd2;
	char	**paths;
	char	*env_path;
	char	*buffer[500];

	pipe(end);
	parent = fork();
	if (parent == -1)
		perror("Fork: ");
	if (parent == 0)
	{
		child_process(cmd1, end, argv, envp);
		read(1, &buffer, 100);
		close(end[0]);
		cmd1 = path_searcher(argv[2], envp);
	}
	child = fork();
	if (child == -1)
		perror("Fork: ");
	if (child == 0)
	{
		parent_process(cmd2, end, argv, envp);
		cmd2 = path_searcher(argv[3], envp);
		write(0, &buffer, 100);
		close(end[0]);
	}
	close(end[0]);
	close(end[1]);
	waitpid(parent, &status, 0);
	waitpid(child, &status, 0);
}
*/
/*
int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;

//	var.fd1 = open(argv[1], O_RDONLY);
	(void)argc;
//	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	var.cmd1 = path_searcher(argv[2], envp);
	var.cmd_args = ft_split(argv[2], ' ');
//	pipex(argv, envp);
	close(var.fd1);
//	close(fd2);
//	free(var.cmd_args);
	return (0);
}
*/
int	main(int argc, char *argv[], char *envp[])
{
	t_var	var;
	char	*buff;

	(void)argc;
	(void)argv;
	(void)envp;
	if (pipe(var.end) == -1)
		return (1);
	var.pid = fork();
	if (var.pid < 0)
		return (2);
	if (var.pid == 0)
	{
		var.cmd_args = ft_split(argv[1], ' ');
		var.cmd = path_searcher(var.cmd_args[0], envp);
		dup2(var.end[1], STDOUT_FILENO);
		close(var.end[0]);
		close(var.end[1]);
		execve(var.cmd, var.cmd_args, NULL);
	}
	waitpid(var.pid, NULL, 0);
	buff = malloc(501);
	read(var.end[0], buff, 500);
	close(var.end[1]);
	ft_printf("%s\n", buff);
	close(var.end[0]);
	free(buff);
	return (0);
}
