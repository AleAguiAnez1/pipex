/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaguirr <alaguirr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:08:14 by alaguirr          #+#    #+#             */
/*   Updated: 2024/09/02 13:17:25 by alaguirr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define WRITE 1
# define READ 0

typedef struct s_pipe
{
	int		tube[2];
	int		infile_fd;
	int		outfile_fd;
	char	**envp;
	char	**args;
	char	*path;
}	t_pipe;

int		open_file(char *infile, t_pipe *pipe);
int		create_file(char *outfile, t_pipe *pipe);
void	child_error(t_pipe *pipe);

void	free_path(char **paths);
char	**get_path(t_pipe *pipe);
int		check_path(char *paths, t_pipe *pipe);
int		get_values(char *command, t_pipe *pipe);

void	make_first_child(t_pipe *pipe, char *arg, char *infile);
void	make_second_child(t_pipe *pipe, char *arg, char *outfile);
int		close_parent(t_pipe *pipe, int child_1, int child_2);

void	args_error(void);
void	pipe_error(void);

#endif
