/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rederections_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:34:12 by aaitoual          #+#    #+#             */
/*   Updated: 2022/06/10 12:12:21 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_printf_error_utils(char *com, int i)
{
	if (i == 3)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(com, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (i == 4)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(com, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (i == 5)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(com, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
}

int	ft_utils_return(t_spl *c, int t, int i)
{
	if (c->a_var[t][i + 1] && !c->a_var[t][i + 1][0])
	{
		ft_printf_error(c->a_var[t][i + 1], 3);
		return (0);
	}
	else
	{
		ft_printf_error("", 2);
		return (0);
	}
	return (1);
}
