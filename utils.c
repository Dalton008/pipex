/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjammie <mjammie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:34:11 by mjammie           #+#    #+#             */
/*   Updated: 2021/06/11 18:38:07 by mjammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_str1;
	int		len_str2;
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	len_str1 = ft_strlen(s1);
	len_str2 = ft_strlen(s2);
	result = (char *)malloc(len_str1 + len_str2 + 1);
	if (result == 0)
		return (0);
	while (n < len_str1)
	{
		result[n] = s1[n];
		n++;
	}
	while (i < len_str2)
		result[n++] = s2[i++];
	result[n] = 0;
	return (result);
}

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned long	n;

	n = 0;
	while ((n < size) && (str1[n] != 0 || str2[n] != 0))
	{
		if (str1[n] != str2[n])
			return ((unsigned char)str1[n] - (unsigned char)str2[n]);
		n++;
	}
	return (0);
}
