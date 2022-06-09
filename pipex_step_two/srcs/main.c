/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/06/09 12:14:44 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_var	get_args(char ac, char *av[])
{
	t_var	var;

	var.fd[0] = open(av[1], O_RDONLY);
	if (var.fd[0] < 0)
		ft_puterror("Error: Impossible to open the file.");
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var.fd[0] < 0)
		ft_puterror("Error: Impossible to open the file.");
	return (var);
}

int	main(int ac, char *av[], char *env[])
{
	t_var	var;
	pid_t	pid;
	int		i;

	if (ac < 5)
		ft_puterror("Error: The number of arguments is incorrect.");
	var = get_args(ac, av);
	i = 3;
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	dup2(var.fd[1], STDOUT_FILENO);
	close(var.fd[1]);
	pid = fork();
	if (pid < 0)
		ft_puterror("Error: Failed to create the fork.");
	if (pid == 0)
		pipex(av[2], env, var.fd[0]);
	while (i < ac - 2)
		pipex(av[i++], env, 1);
	waitpid(-1, &var.status, 0);
	return (0);
}
