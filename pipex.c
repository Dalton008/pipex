/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:20:47 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/12 16:01:15 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	**get_path(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (env[i])
	{
		if ((ft_strncmp(env[i], "PATH=", 5)) == 0)
			path = ft_split(env[i] + 5, ':');
		i++;
	}
	return (path);
}

char	*join_path_to_file(char *path, char *cmd)
{
	char	*result;
	char	*for_free;

	for_free = cmd;
	cmd = ft_strjoin("/", cmd);
	result = ft_strjoin(path, cmd);
	free(cmd);
	return (result);
}

void	child(int *pfd, char **argv, char **env)
{
	t_all	all;

	all.i = 0;
	all.path = get_path(env);
	all.cmd = ft_split(argv[2], ' ');
	while (all.path[all.i])
	{
		all.pt = join_path_to_file(all.path[all.i], all.cmd[0]);
		all.op = open(all.pt, O_RDONLY);
		if (all.op != -1)
			break ;
		all.i++;
	}
	if (all.op == -1)
		perror("Invalid command!\n");
	close(pfd[0]);
	dup2(pfd[1], 1);
	close(pfd[1]);
	dup2(all.file, 0);
	execve(all.pt, all.cmd, env);
	all.file = open(argv[1], O_RDONLY, 0777);
	close(all.op);
}

void	parent(int *pfd, char **argv, char **env)
{
	t_all	all;

	all.i = 0;
	all.file = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	all.path = get_path(env);
	all.cmd = ft_split(argv[3], ' ');
	while (all.path[all.i])
	{
		all.pt = join_path_to_file(all.path[all.i], all.cmd[0]);
		all.op = open(all.pt, O_RDONLY);
		if (all.op != -1)
			break ;
		all.i++;
	}
	if (all.op == -1)
		perror("Invalid command!\n");
	close(pfd[1]);
	dup2(pfd[0], 0);
	close(pfd[0]);
	dup2(all.file, 1);
	execve(all.pt, all.cmd, env);
	close(all.op);
}

int	main(int argc, char **argv, char **env)
{
	int		pfd[2];
	pid_t	pid;

	if (pipe(pfd) == -1 || argc < 5 || argc > 5)
	{
		perror("Error!");
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		child(pfd, argv, env);
	}
	else
	{
		parent(pfd, argv, env);
	}
}
