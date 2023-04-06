/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:14:19 by gecasado          #+#    #+#             */
/*   Updated: 2021/10/13 20:16:16 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wordcount(char *s, char c)
{
	int	count;

	count = 0;
	if (*s == '\0')
		return (0);
	s++;
	if (*s == '\0' && *(s - 1) != c)
		return (1);
	while (*s)
	{
		if (*(s - 1) != c && *s == c)
			count++;
		s++;
	}
	if (*(s - 1) != c)
		count++;
	return (count);
}

int	wordlen(char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0' && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static char	**splitter(char const *s, char c)
{
	int		i;
	int		j;
	char	**t;

	i = 0;
	t = (char **)malloc(sizeof(char *) * (wordcount((char *)s, c) + 1));
	if (!t)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		j = 0;
		t[i] = ((char *)malloc(wordlen((char *)s, c) + 1));
		if (!t[i])
			return (NULL);
		while (*s != c && *s != '\0')
		{
			t[i][(j++)] = *s;
			s++;
		}
		t[(i++)][j] = '\0';
	}
	t[i] = NULL;
	return (t);
}

char	**ft_split(char const *s, char c)
{
	char	*trimmed;
	char	totrim[2];
	char	**t;

	if (!s)
		return (NULL);
	if (ft_strcmp(s, "") == 0)
	{
		t = malloc(sizeof(char *));
		if (!t)
			return (NULL);
		*t = NULL;
		return (t);
	}
	totrim[0] = c;
	totrim[1] = '\0';
	trimmed = ft_strtrim(s, totrim);
	if (!trimmed)
		return (NULL);
	t = splitter(trimmed, c);
	if (!t)
		return (NULL);
	free(trimmed);
	return (t);
}
