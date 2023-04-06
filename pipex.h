/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:53:33 by gecasado          #+#    #+#             */
/*   Updated: 2021/10/14 17:33:48 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strtrim(char const *s1, char const *set);
int		wordcount(char *s, char c);
int		wordlen(char *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int star, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**getpath(char *envp[]);
char	**splitarg(char *argv);
void	check_fd(int fd, char *file);
void	checkargc(int argc);
void	childprocess1(int *fd, char **argv, char **envp);
void	childprocess2(int *fd, char **argv, char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
