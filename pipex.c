/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:04:47 by gecasado          #+#    #+#             */
/*   Updated: 2021/10/14 17:34:34 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	workfd(int *fd, char **argv)
{
	int	fdaux;

	close(fd[0]);
	fdaux = open (argv[1], O_RDONLY);
	check_fd(fdaux, argv[1]);
	dup2(fdaux, STDIN_FILENO);
	close(fdaux);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
}

void	workfd2(int *fd, int status)
{
	close(fd[0]);
	wait(NULL);
	waitpid(-1, &status, 0);
}	

void	childprocess1(int *fd, char **argv, char **envp)
{
	char	**arg;
	char	**copy;
	int		x;
	int		ret;

	workfd(fd, argv);
	arg = splitarg(argv[2]);
	copy = getpath (envp);
	x = 0;
	ret = execve(arg[0], arg, envp);
	while (copy[x] != NULL)
	{
		copy[x] = ft_strjoin(copy[x], arg[0]);
		ret = execve(copy[x], arg, envp);
		if (ret == -1)
			x++;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(*arg, 2);
}

void	childprocess2(int *fd, char **argv, char **envp)
{
	char	**arg;
	char	**copy;
	int		fdaux2;
	int		x;
	int		ret;

	fdaux2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fdaux2, STDOUT_FILENO);
	close(fdaux2);
	arg = splitarg(argv[3]);
	copy = getpath (envp);
	x = 0;
	ret = execve(arg[0], arg, envp);
	while (ret < 0 && copy[x] != NULL)
	{
		copy[x] = ft_strjoin(copy[x], arg[0]);
		ret = execve(copy[x], arg, envp);
		if (ret == -1)
			x++;
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(*arg, 2);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		status;
	pid_t	pid;

	checkargc(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("error");
	if (pid == 0)
		childprocess1(fd, argv, envp);
	else
	{
		close(fd[1]);
		pid = fork();
		if (pid == -1)
			perror("error");
		if (pid == 0)
			childprocess2(fd, argv, envp);
		else
			workfd2(fd, status);
	}
	return (0);
}
