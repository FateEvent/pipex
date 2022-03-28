/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:18:01 by faventur          #+#    #+#             */
/*   Updated: 2022/03/28 13:45:21 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_error(char *pathname, int errnum)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putendl_fd(strerror(errnum), 2);
}
