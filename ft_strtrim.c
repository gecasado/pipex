/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:05:11 by gecasado          #+#    #+#             */
/*   Updated: 2021/10/13 20:09:31 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_can_trim(char c, char const *set)
{
	int		count;

	count = -1;
	while (set[++count])
		if (set[count] == c)
			return (1);
	return (0);
}

static int	ft_get_size(char const *s1, char const *set)
{
	int		count;
	int		size;

	count = 0;
	size = ft_strlen(s1);
	while (ft_can_trim(s1[size - count - 1], set))
		count++;
	return (size - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count;
	int		size;
	char	*tab;

	count = 0;
	size = 0;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	while (ft_can_trim(s1[count], set))
		count++;
	if (count == (int)ft_strlen(s1))
		return (ft_strdup(""));
	size = ft_get_size(s1 + count, set) + 1;
	tab = (char *)malloc((size) * sizeof(char));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1 + count, size);
	return (tab);
}
