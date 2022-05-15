/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/05/15 20:47:18 by faventur         ###   ########.fr       */
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

char	*ft_parser(char *cmd, char *envp[])
{
	char	**paths;
	char	*exec_path;
	char	*env_path;
	char	**cmd_args;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	while (envp[i++])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			env_path = envp[i] + 5;
			break ;
		}
	}
	paths = ft_split(env_path, ':');
	i = 0;
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
		cmd1 = ft_parser(argv[2], envp);
	}
	child = fork();
	if (child == -1)
		perror("Fork: ");
	if (child == 0)
	{
		parent_process(cmd2, end, argv, envp);
		cmd2 = ft_parser(argv[3], envp);
		write(0, &buffer, 100);
		close(end[0]);
	}
	close(end[0]);
	close(end[1]);
	waitpid(parent, &status, 0);
	waitpid(child, &status, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd1;
//	int		fd2;
	char	*cmd1;
	char	*env_path;
	char	**cmd_args;

	fd1 = open(argv[1], O_RDONLY);
//	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
/*
	if (fd1 == -1 || fd2 == -1)
	{
		perror("La cata!");
		return (-1);
	}
*/
	dup2(fd1, 0);
//	dup2(fd2, 1);
	cmd1 = ft_parser(argv[2], envp);
	cmd_args = ft_split(argv[2], ' ');
	execve(cmd1, cmd_args, NULL);
	pipex(argv, envp);
	close(fd1);
//	close(fd2);
//	free(cmd_args);
	return (0);
}
