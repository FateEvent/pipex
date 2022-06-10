/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:19 by faventur          #+#    #+#             */
/*   Updated: 2022/06/10 12:50:38 by faventur         ###   ########.fr       */
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
# include <ft_printf_fd.h>
# include <get_next_line.h>

typedef struct s_var
{
	pid_t	pid;
	int		fd[2];
	int		end[2];
	int		status;
}			t_var;

void	ft_puterror(const char *str);
void	ft_arr_freer(char **arr);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
int		ft_strstrbool(const char *haystack, const char *needle);

t_var	get_args(char ac, char *av[]);
void	pipex(char *cmd, char *env[], int fdin);
void	ft_exec(char *cmd, char *env[]);
char	*ft_path_searcher(char *cmd, char *envp[]);

#endif