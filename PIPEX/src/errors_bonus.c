/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:53:00 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/01/18 13:50:52 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	cmd_err(char **cmd)
{
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putstr_fd(": command not found", STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	free_split(cmd);
	exit(EXIT_FAILURE);
}

void	err_arg(void)
{
	ft_putstr_fd("usage: ./pipex [file1] [cmd1] [cmd2] [file2]", STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void	gen_err(char *err)
{
	if (errno == 0)
		ft_putstr_fd("Error", STDERR_FILENO);
	else
		perror(err);
	exit(EXIT_FAILURE);
}
