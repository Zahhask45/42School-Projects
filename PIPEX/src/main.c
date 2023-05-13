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

#include "pipex.h"

// for bonus need a while until last two arg of argv
void	first_cmd(int *pipefd, int *fd, char **argv, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		gen_err("fork");
	if (c_pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			gen_err(argv[1]);
		cmd = ft_split(argv[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
			cmd_err(cmd);
	}
}

void	second_cmd(int *pipefd, int *fd, char **argv, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	c_pid = fork();
	if (c_pid < 0)
		gen_err("fork");
	if (c_pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			gen_err(argv[4]);
		cmd = ft_split(argv[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if (cmd[0] && path(cmd[0], envp))
		{
			execve(path(cmd[0], envp), cmd, envp);
			free_split(cmd);
		}
		else
			cmd_err(cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	fd[2];

	errno = 0;
	if (argc != 5)
		err_arg();
	if (pipe(pipefd) < 0)
		gen_err(NULL);
	first_cmd(pipefd, fd, argv, envp);
	second_cmd(pipefd, fd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	return (EXIT_SUCCESS);
}
