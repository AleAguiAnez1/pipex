/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaguirr <alaguirr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:08:51 by alaguirr          #+#    #+#             */
/*   Updated: 2024/09/02 12:10:57 by alaguirr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_parent(t_pipe *pipex, int child_1, int child_2)
{
	int	status;

	close(pipex->tube[0]);
	close(pipex->tube[1]);
	waitpid(child_1, NULL, 0);
	waitpid(child_2, &status, 0);
	return (WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe pipex;
	pid_t child_1;
	pid_t child_2;
	int status;

	if (argc != 5)
		args_error();
	if (envp != NULL)
		pipex.envp = envp;
	if (pipe(pipex.tube) == -1)
		pipe_error();
	child_1 = fork();
	if (child_1 == -1)
		exit(1);
	if (child_1 == 0)
		make_first_child(&pipex, argv[2], argv[1]);
	child_2 = fork();
	if (child_2 == -1)
		exit(1);
	if (child_2 == 0)
		make_second_child(&pipex, argv[3], argv[4]);
	status = close_parent(&pipex, child_1, child_2);
	exit(status);
}