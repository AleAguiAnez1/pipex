/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaguirr <alaguirr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:11:38 by alaguirr          #+#    #+#             */
/*   Updated: 2024/09/02 12:43:51 by alaguirr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	pipe_error(void)
{
	ft_printf("Pipe error\n");
	exit(1);
}

void	args_error(void)
{
	ft_printf("Invalid args: [infile cmd1 cmd2 outfile]\n");
	exit (1);
}