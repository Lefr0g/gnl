/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:27:47 by amulin            #+#    #+#             */
/*   Updated: 2015/02/05 17:38:44 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;
	int		ret;

	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr("Main >> Error : Please enter a parameter\n");
		else
			ft_putstr("Main >> Error : Too many parameters\n");
		return (0);
	}
	ft_putstr("Main >> Opening file '");
	ft_putstr(argv[1]);
	ft_putstr("'...\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Main >> Open fail, end of test.\n");
		return (1);
	}
	ft_putstr("Main >> File successfully opened on fd = ");
	ft_putnbr(fd);
	ft_putchar('\n');

	ft_putstr("Main >> Testing GNL on this file descriptor...\n");
	i = 0;
	ret = get_next_line(fd, &line);
	while (ret == 1)
	{
		ft_putstr("Main >> GNL run ");
		ft_putnbr(i);
		ft_putstr(", line read gives : ");
		ft_putstr(line);
		ft_putstr("\n");
		ret = get_next_line(fd, &line);
		i++;
	}
	if (ret == 0)
		ft_putstr("Main >> GNL returns 0, read over\n");
	if (ret == -1)
		ft_putstr("Main >> GNL returns -1, error");
//

	ft_putstr("Main >> Closing file...\n");
	if (close(fd) != 0)
	{
		ft_putstr("Main >> Close failed, end of test.\n");
		return (1);
	}
	ft_putstr("Main >> File successfully closed.\n");
	ft_putstr("Main >> Test completed, end of program.\n");
	return (0);
}
