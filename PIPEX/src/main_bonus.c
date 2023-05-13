/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:15:39 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/01/18 14:01:12 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_cmd(int *pipefd, int *fd, char *argv, char **envp)
{
	char	**cmd;
	pid_t	pid;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		gen_err("fork");
	if (pid == 0)
	{
		cmd = ft_split(argv, ' ');
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else if (fd == STDIN_FILENO)
			cmd_err(cmd);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
}

void	second_cmd(int *pipefd, int *fd, char *argv, char **envp)
{
	char	**cmd;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		gen_err("fork");
	if (pid == 0)
	{
		cmd = ft_split(argv, ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else if (fd == STDIN_FILENO)
			cmd_err(cmd);
	}
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	i;

	i = 1;
	errno = 0;
	if (argc < 5)
		err_arg();
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		gen_err(argv[1]);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		gen_err(argv[argc - 1]);
	while (++i < argc - 2)
	{
		open_cmd(pipefd, fd, argv[i], envp);
	}
	second_cmd(pipefd, fd, argv[i], envp);
	close(pipefd[0]);
	close(pipefd[1]);
	return (EXIT_SUCCESS);
}
