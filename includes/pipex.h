/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:19 by faventur          #+#    #+#             */
/*   Updated: 2022/06/07 22:48:10 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include "ft_printf.h"

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
	char	*buffer;
}				t_var;

size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_arr_freer(char **arr);

char	*ft_path_searcher(char *cmd, char *envp[]);

void	print_error(char *pathname, int errnum);

#endif