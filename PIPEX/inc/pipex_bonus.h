/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:16:13 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/01/18 16:09:07 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	cmd_err(char **cmd);
void	err_arg(void);
void	gen_err(char *err);
void	free_split(char **args);
char	*path(char *cmd, char **envp);

#endif
