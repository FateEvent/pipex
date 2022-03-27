/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:17:19 by faventur          #+#    #+#             */
/*   Updated: 2022/03/27 15:35:05 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>

# include "libft/libft.h"

# define MAX_SIZE 2900

void	open_and_read(char *buffer, char *arg);
void	print_error(char *pathname, int errnum);
void	open_and_write(char *buffer, int argc, char *argv[], int i);
void	open_and_append(char *buffer, int argc, char *argv[], int i);

#endif