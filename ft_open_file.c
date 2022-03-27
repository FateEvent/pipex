/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:18:01 by faventur          #+#    #+#             */
/*   Updated: 2022/03/27 15:29:17 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	open_and_read(char *buffer, char *arg)
{
	int	fd;
	int	bytes_read;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		print_error(arg, ENOENT);
	else
	{
		bytes_read = read(fd, &buffer, MAX_SIZE);
		if (bytes_read == -1)
			return ;
		close(fd);
		buffer[bytes_read] = '\0';
	}
}

void	print_error(char *pathname, int errnum)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putendl_fd(strerror(errnum), 2);
}

void	open_and_write(char *buffer, int argc, char *argv[], int i)
{
	int	fd;
	int	bytes_written;

	(void) argc;
	(void) argv;
	fd = open(argv[i + 1], O_WRONLY | O_CREAT);
	if (fd == -1)
		return ;
	bytes_written = write(fd, buffer, ft_strlen(buffer));
	if (bytes_written == -1)
		return ;
	close(fd);
}

void	open_and_append(char *buffer, int argc, char *argv[], int i)
{
	int	fd;
	int	added_bytes;

	(void) argc;
	(void) argv;
	fd = open(argv[i + 1], O_WRONLY | O_CREAT | O_APPEND);
	if (fd == -1)
		return ;
	added_bytes = write(fd, buffer, ft_strlen(buffer));
	if (added_bytes == -1)
		return ;
	close(fd);
}
