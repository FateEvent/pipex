/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:19 by faventur          #+#    #+#             */
/*   Updated: 2022/06/09 13:16:02 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_var
{
	pid_t	pid;
	int		fd[2];
	int		end[2];
	int		status;
}			t_var;

size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_puterror(const char *str);
void	ft_arr_freer(char **arr);
char	*ft_path_searcher(char *cmd, char *envp[]);

t_var	get_args(char ac, char *av[]);
void	pipex(char *cmd, char *env[], int fdin);
void	ft_exec(char *cmd, char *env[]);

#endif