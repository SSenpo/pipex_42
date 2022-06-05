/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:25:14 by mmago             #+#    #+#             */
/*   Updated: 2022/03/08 14:30:40 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **av, char **envp, int *fd)
{
	int	file1;

	file1 = open(av[1], O_RDONLY, 0644);
	if (file1 == -1)
	{
		error();
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(file1, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	file2;

	file2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file2 == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == 0)
			child_process(av, envp, fd);
		if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			parent_process(av, envp, fd);
		}
		else
			error();
	}
	else
	{
		write(1, "Ошибка: не верное колличество аргументов.\n", 77);
	}
	return (0);
}
