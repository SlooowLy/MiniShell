/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:25:32 by mfagri            #+#    #+#             */
/*   Updated: 2022/06/12 12:24:14 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_export(char **t, int i, int k)
{
	int	j;
	int	l;

	i = -1;
	while (t[++i])
	{
		k = 0;
		if (t[i][0])
			write (1, "declare -x ", 11);
		j = -1;
		l = 0;
		while (t[i][++j])
		{
			write(1, &t[i][j], 1);
			if (t[i][j] == '=')
			{
				k = 1;
				if (l == 0 && ++l)
					write (1, "\"", 1);
			}
		}
		if (k == 1)
			write (1, "\"", 1);
		write (1, "\n", 1);
	}
}

int	ft_do_nothing(char *arg)
{
	int	j;
	int	a;
	int	n;

	a = 0;
	n = 0;
	j = 0;
	while (arg[j])
	{
		if (!(ft_isalpha(arg[j])) && (arg[j] != '_'))
			break ;
		if (ft_isalpha(arg[j]))
			a++;
		if (arg[j] == '_')
			n++;
		j++;
	}
	if (n == 1)
		return (1);
	else if (n == 1 && a == 0)
		return (1);
	return (0);
}

char	*final_srt(char *arg, char *name, int i)
{
	char	*value;
	char	*f;
	int		j;

	f = malloc(1);
	f[0] = '\0';
	value = malloc(ft_strlen(arg) - i + 1);
	j = 0;
	while (arg[i] && arg[++i])
	{
		value[j] = arg[i];
		j++;
	}
	value[i] = '\0';
	f = ft_strjoin(f, name);
	if (ft_strchr(arg, '='))
		f = ft_strjoin(f, "=");
	if (value[0])
		f = ft_strjoin(f, value);
	free(value);
	return (f);
}

int	export_is_invalid(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '+' || arg[0] == '=')
		return (1);
	while (arg[i++] && arg[i] != '=')
	{
		if (arg[i] == '_')
		{
			while (arg[i] == '_')
				i++;
		}
		if (arg[i] == '+' && arg[i + 1] == '=' && i)
			break ;
		else if (ft_isdigit(arg[0]) || (!ft_isalpha(arg[i])
				&& !ft_isdigit(arg[i]) && arg[i++])
			|| (!ft_isalpha(arg[0]) && arg[0] != '_'))
			return (1);
	}
	return (0);
}

void	ft_export(char **env, char **arg, int fd)
{
	int		i;
	int		l;
	char	**t;

	t = ft_sort_env(env);
	i = 0;
	i = 1;
	l = 0;
	l = ft_export_utils(env, arg, i, t);
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
	if (l)
	{
		if (!fd)
			exit (0);
		get_glo_2(1, 0);
		return ;
	}
	if (!fd)
		exit (1);
	get_glo_2(1, 1);
}
