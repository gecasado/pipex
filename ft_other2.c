/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:23:56 by gecasado          #+#    #+#             */
/*   Updated: 2021/10/13 20:25:54 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	s = ((char *)malloc(sizeof(*s) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s)
		return (0);
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = 0;
	return (s);
}

char	**getpath(char *envp[])
{
	char	*c;
	int		i;
	size_t	j;
	char	**getp;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	j = ft_strlen(envp[i]);
	c = ft_substr(envp[i], 5, j);
	getp = ft_split(c, ':');
	i = 0;
	while (getp[i] != NULL)
	{
		getp[i] = ft_strjoin(getp[i], "/");
		i++;
	}
	return (getp);
}

char	**splitarg(char *argv)
{
	char	**arg;

	arg = ft_split(argv, ' ');
	return (arg);
}

void	check_fd(int fd, char *file)
{
	if (fd == -1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
		exit(0);
	}
}

void	checkargc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("./pipex archivo1 comando1 comando2 archivo2\n", 2);
		exit(0);
	}
}
