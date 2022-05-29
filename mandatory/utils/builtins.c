/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 04:30:33 by mfagri            #+#    #+#             */
/*   Updated: 2022/05/25 15:43:52 by mfagri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_check_n(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if ((!s1 || !s2))
		return (1);
	if (s1[i] == '-')
	{
		i++;
		while (s1[i])
		{
			if (s1[i] != 'n')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_echo(char **pr)
{
	int		i;
	int		n_option;

	i = 1;
	n_option = 0;
	while (pr[i] && ft_check_n(pr[i], "-n") == 0)
	{
		n_option = 1;
		i++;
	}
	while (pr[i])
	{
		ft_putstr_fd(pr[i], 1);
		if (pr[i + 1] && pr[i][0] != '\0')
			write(1, " ", 1);
		i++;
	}
	if (n_option == 0)
		write(1, "\n", 1);
}

void	ft_pwd(void)
{
	char	s[1024];

	getcwd(s, sizeof(s));
	printf("%s\n", s);
}

void	ft_unset(char **arg, char **env)
{
	int	i;

	i = 0;
	while (arg[++i])
		remove_from_env(arg[i], env, 0);
}