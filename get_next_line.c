/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:04:13 by amulin            #+#    #+#             */
/*   Updated: 2015/02/02 16:41:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_read(ssize_t *ret, int const *fd, char *buff, char *tmp)
{
	char	*flash;
	char	*buff;

	buff = ft_strnew(BUFF_SIZE);
	if (buff == NULL)
		return (-1);
	*ret = read(*fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	if (ret == -1)
		return (-1);
	flash = tmp;
	tmp = ft_strnew(ft_strlen(flash) + BUFF_SIZE);
	if (tmp == NULL)
		return (-1);
	ft_strcpy(tmp, flash);
	ft_strcat(tmp, buff);
	ft_strdel(&flash);
}

int	get_next_line(int const fd, char **line)
{
	static t_keep	keep;
	char			*tmp;
	ssize_t			ret;


	if (!(fd <= keep.fdmax && keep.str[fd] != NULL))
		gnl_createkeep(fd, keep);
	else
	{
		tmp = ft_strdup(keep.str[fd]);
		if (tmp == NULL)
			return (-1);
		if (gnl_read(&ret, &fd, buff, tmp) == -1)
			return (-1);



	}
}

