/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:04:13 by amulin            #+#    #+#             */
/*   Updated: 2015/01/23 17:15:11 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	Fonctions necessaires :
//	- get_next_line
//	- Augmentation de la taille de t_keep
//	- Reallocation chaine puis concatenation
//	- strlenline
//

int	get_next_line(int const fd, char **line)
{
	static t_keep	keep;
	char			*buff;
	char			*tmp;
}
