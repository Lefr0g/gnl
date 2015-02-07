/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:04:13 by amulin            #+#    #+#             */
/*   Updated: 2015/02/07 14:54:03 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (i != -1)
	{
		*line = ft_strsub(*tmp, 0, i);
		if (*line == NULL)
			return (-1);
		ft_strdel(&(keep->str));
		keep->str = ft_strdup(&tmp[0][i + 1]);
	}
	else
	{
		*line = ft_strdup(*tmp);
		ft_strdel(&(keep->str));
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
	if (gnl_read(&ret, &fd, &tmp) == -1)
		return (-1);
	gnl_write(&tmp, line, &keep);
	if (ret != BUFF_SIZE && keep.str == NULL)
		return (0);
	else
		return (1);
}
