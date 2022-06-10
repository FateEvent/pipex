/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:43:57 by faventur          #+#    #+#             */
/*   Updated: 2022/06/10 17:39:32 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_var	get_args(char ac, char *av[])
{
	t_var	var;

	var.fd[0] = open(av[1], O_RDONLY);
	if (var.fd[0] < 0)
		ft_printerror("pipex", av[1]);
	var.fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (var.fd[1] < 0)
		ft_printerror("pipex", av[ac - 1]);
	return (var);
}

int	main(int ac, char *av[], char *env[])
{
	t_var	var;
	int		i;

	if (ac < 5)
		ft_puterror("Error: The number of arguments is incorrect.");
	if (!ft_strstrbool(av[1], "here_doc")) // check args for >>
	{
		var = hd_managing(ac, av);
		i = 3;
	}
	else
	{
		var = get_args(ac, av);
		i = 2;
	}
	dup2(var.fd[0], STDIN_FILENO);
	close(var.fd[0]);
	dup2(var.fd[1], STDOUT_FILENO);
	close(var.fd[1]);
	pipex(av[i++], env, var.fd[0]);
	while (i < ac - 2)
		pipex(av[i++], env, 1);
	ft_exec(av[i], env);
	return (0);
}
