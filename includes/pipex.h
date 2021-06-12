/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:47:54 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/11 18:17:33 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_all
{
	char	**cmd;
	char	**path;
	char	*pt;
	int		i;
	int		op;
	int		file;
}				t_all;

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif