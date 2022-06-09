/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:50:39 by aaitoual          #+#    #+#             */
/*   Updated: 2022/06/09 10:36:18 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

static size_t	lenp(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	dest = malloc (sizeof (char) * (ft_strlen(src) + 2));
	while (src && src[i])
	{
		// printf ("%c", src[i]);
		dest[i] = src[i];
		i++;
	}
	// printf ("\n");
	dest[i] = '\0';
	return (dest);
}
