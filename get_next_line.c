/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:04:13 by amulin            #+#    #+#             */
/*   Updated: 2015/02/05 16:25:32 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_createkeep(int const fd, t_hold *keep)
{
	t_hold	copy;
	char	*tmp;
	int		i;

	i = 0;
	copy = *keep;
	keep->str = NULL;
	keep->str = (char**)malloc(sizeof(char*) * fd);
	tmp = ft_strnew(0);
	if (tmp == NULL)
		return (-1);
	keep->fdmax = fd;
	while (i <= fd)
	{
		keep->str[i] = NULL;
		if (copy.str[i] != NULL)
		{
			keep->str[i] = copy.str[i];
		}
		i++;
	}
	keep->str[fd] = tmp;
	return (0);
}

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

int		gnl_write(char **tmp, char **line, t_hold *keep, int const fd)
{
	int	i;

	i = gnl_lenline(*tmp);
	if (i != -1)
	{
		*line = ft_strsub(*tmp, 0, i);
		if (*line == NULL)
			return (-1);
		ft_strdel(&keep->str[fd]);
		keep->str[fd] = ft_strdup(tmp[i]);
	}
	else
		*line = ft_strdup(*tmp);
	ft_strdel(tmp);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_hold	keep = {NULL, -1};
	char			*tmp;
	ssize_t			ret;

	if (!(fd <= keep.fdmax && keep.str[fd] != NULL))
	{
		if (gnl_createkeep(fd, &keep) == -1)
			return (-1);
	}
	tmp = ft_strdup(keep.str[fd]);
	if (tmp == NULL)
		return (-1);
	if (gnl_read(&ret, &fd, &tmp) == -1)
		return (-1);
	gnl_write(&tmp, line, &keep, fd);
	if (ret == BUFF_SIZE && keep.str[fd] != '\0')
		return (1);
	else
		return (0);
}
