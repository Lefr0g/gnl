/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:04:13 by amulin            #+#    #+#             */
/*   Updated: 2015/02/05 18:48:30 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

int		gnl_lenline(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int		gnl_read(ssize_t *ret, int const *fd, char **tmp)
{
	char	*flash;
	char	*buff;

	buff = ft_strnew(BUFF_SIZE);
	if (buff == NULL)
		return (-1);
	*ret = BUFF_SIZE;
	while (gnl_lenline(*tmp) == -1 && *ret == BUFF_SIZE)
	{
		*ret = read(*fd, buff, BUFF_SIZE);
		if (*ret == -1)
			return (-1);
		buff[*ret] = '\0';
		flash = *tmp;
		*tmp = ft_strnew(ft_strlen(flash) + BUFF_SIZE);
		if (tmp == NULL)
			return (-1);
		ft_strcpy(*tmp, flash);
		ft_strcat(*tmp, buff);
		ft_strdel(&flash);
	}
	ft_strdel(&buff);
	return (0);
}

int		gnl_write(char **tmp, char **line, t_hold *keep)
{
	int	i;

	i = gnl_lenline(*tmp);
	ft_strdel(line);
//	printf("GNL >> gnl_write 1 OK\n");
	if (i != -1)
	{
//		printf("GNL >> gnl_write 2a OK\n");
		*line = ft_strsub(*tmp, 0, i);
//		printf("GNL >> gnl_write 2b OK\n");
		if (*line == NULL)
			return (-1);
//		printf("GNL >> gnl_write 2c OK\n");
		ft_strdel(&(keep->str));
//		printf("GNL >> gnl_write 2d OK\n");
		keep->str = ft_strdup(&tmp[0][i + 1]);
//		printf("GNL >> gnl_write 2e OK\n");
//		printf("GNL >> gnl_write tmp remain = '%s'\n", *tmp);
//		printf("GNL >> gnl_write keep->str = '%s'\n", keep->str);
	}
	else
	{
		*line = ft_strdup(*tmp);
		ft_strdel(&(keep->str));
		keep->str = ft_strdup("");
	}
	ft_strdel(tmp);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_hold	keep = {NULL, -1};
	char			*tmp;
	ssize_t			ret;

	tmp = ft_strnew(BUFF_SIZE);
	if (tmp == NULL)
		return (-1);
	if (keep.str)
		tmp = ft_strdup(keep.str);
//	printf("GNL >> get_next_line 1 OK\n");
	if (gnl_read(&ret, &fd, &tmp) == -1)
		return (-1);
//	printf("GNL >> get_next_line 2 OK\n");
	gnl_write(&tmp, line, &keep);
//	printf("GNL >> get_next_line 3 OK\n");
	if (ret != BUFF_SIZE && keep.str[0] == '\0')
		return (0);
	else
		return (1);
}
