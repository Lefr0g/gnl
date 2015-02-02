/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:04:06 by amulin            #+#    #+#             */
/*   Updated: 2015/02/02 15:29:04 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft.h"
# include <unistd.h>

typedef	struct	s_hold
{
	char	**str;
	int		fdmax;
}				t_hold;

int				get_next_line(int const fd, char **line);

#endif
