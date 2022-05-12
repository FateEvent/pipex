/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:37 by faventur          #+#    #+#             */
/*   Updated: 2022/04/30 11:38:20 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackclear() function suppresses and frees the memory of the
** the element passed as a parameter and of all the following elements
** by using the del function and free(3). Finally, the initial pointer
** is to be set to NULL.
*/

#include "stacks.h"

void	ft_stackclear(t_stack *stack, void (*del)(void *))
{
	t_node	*temp;
	t_node	*delenda;

	if (!stack || !del)
		return ;
	delenda = stack->top;
	while (delenda != NULL)
	{
		temp = delenda->next;
		ft_stackdelone(delenda, del);
		delenda = temp;
	}
}
