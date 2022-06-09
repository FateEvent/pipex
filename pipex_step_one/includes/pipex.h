/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:19 by faventur          #+#    #+#             */
/*   Updated: 2022/06/09 11:28:18 by faventur         ###   ########.fr       */
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
	int		fd[2];
	int		end[2];
	int		status;
	pid_t	pid[2];
	char	*cmd1;
	char	*cmd2;
	char	**cmd_args1;
	char	**cmd_args2;
}				t_var;

size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_puterror(const char *str);
void	ft_arr_freer(char **arr);
char	*ft_path_searcher(char *cmd, char *envp[]);

t_var	get_args(char *av[], char *envp[]);

#endif