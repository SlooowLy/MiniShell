/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:51:12 by aaitoual          #+#    #+#             */
/*   Updated: 2021/11/05 15:51:51 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../minishell.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c && c[i])
		i++;
	return (i);
}
