/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaguirr <alaguirr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:10:24 by alaguirr          #+#    #+#             */
/*   Updated: 2024/09/02 12:15:06 by alaguirr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	**get_path(t_pipe *pipe)
{
	int		i;
	char	**paths;

	i = 0;
	while (pipe->envp[i])
	{
		if (ft_strncmp(pipe->envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(&pipe->envp[i][5], ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

int	check_path(char *paths, t_pipe *pipe)
{
	char	*join;
	char	*command;

	join = ft_strjoin(paths, "/");
	command = ft_strjoin(join, pipe->args[0]);
	free(join);
	if (access (command, X_OK) == 0)
	{
		pipe->path = command;
		return (0);
	}
	free(command);
	return (1);
}

int	get_values(char *command, t_pipe *pipe)
{
	int		i;
	char	**paths;

	i = 0;
	pipe->args = ft_split(command, ' ');
	if (ft_strchr(pipe->args[0], '/') != NULL)
	{
		pipe->path = pipe->args[0];
		return (0);
	}
	paths = get_path(pipe);
	if (!paths)
		return (1);
	while (paths[i])
	{
		if (check_path(paths[i], pipe) == 0)
		{
			free_path(paths);
			return (0);
		}
		i++;
	}
	free_path(paths);
	return (1);
}
