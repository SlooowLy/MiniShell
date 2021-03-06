/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:30:52 by aaitoual          #+#    #+#             */
/*   Updated: 2022/06/11 12:47:37 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_env(char **env, int fd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
		{
			ft_putstr_fd(env[i], 1);
			write(1, "\n", 1);
		}
		i++;
	}
	if (!fd)
		exit (0);
}

static int	count(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	return (i);
}

int	remove_from_env_utils(char **env, char *arg, int l, int *i)
{
	int		j;

	*i = -1;
	while (env[++(*i)])
	{
		j = (*i) + 1;
		if (strncmp(arg, env[*i], count(env[*i])) == 0
			&& (count(env[*i]) == ft_strlen(arg)))
		{
			free (env[*i]);
			l = 1;
			while (env[j])
				env[(*i)++] = env[j++];
		}
	}
	return (l);
}

void	remove_from_env(char *arg, char **env, int l, int fd)
{
	int	i;

	if (export_is_invalid(arg))
	{
		ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		if (!fd)
			exit (1);
		return ;
	}
	l = remove_from_env_utils(env, arg, l, &i);
	if (l)
		env[i - 1] = NULL;
}
