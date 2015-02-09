/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speedtest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:27:47 by amulin            #+#    #+#             */
/*   Updated: 2015/02/07 12:46:18 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	(void)ac;
	(void)av;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	return (0);
}
