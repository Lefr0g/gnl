/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:27:47 by amulin            #+#    #+#             */
/*   Updated: 2015/02/07 12:46:18 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	run_gnl(int fd, char **line)
{
	int	ret;
	int	i;

	ft_putstr("Main >> Testing GNL on file descriptor ");
	ft_putnbr(fd);
	ft_putstr(" ...\n");
	i = 0;
	ret = get_next_line(fd, line);
	ft_putstr("Main >> First GNL success\n");
	while (ret == 1)
	{
		ft_putstr("Main >> GNL run ");
		ft_putnbr(i);
		ft_putstr(", GNL returns 1, line read gives : '");
		ft_putstr(*line);
		ft_putstr("'\n");
		ret = get_next_line(fd, line);
//		printf("Main >> run_gnl loop, i = %d\n", i);
		i++;
	}
	if (ret == 0)
	{
		ft_putstr("Main >> GNL run ");
		ft_putnbr(i);
		ft_putstr(", GNL returns 0, line read gives : '");
		ft_putstr(*line);
		ft_putstr("'\n");
		ft_putstr("Main >> GNL returned 0, read over\n");
	}
	if (ret == -1)
		ft_putstr("Main >> GNL returns -1, error\n");
	return (0);
}

void	run_read_stdin(void)
{
	int		buffsize;
	int		ret;
	char	*buff;

	buffsize = 30;
	buff = ft_strnew(buffsize);
	ret = read(0, buff, buffsize);
	printf("(TBDel)Main >> ret = %d\n", ret);
	printf("(TBDel)Main >> buff contains '%s'\n", buff);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = ft_strnew(BUFF_SIZE);
	ft_strcpy(line, "Hello");
	ft_putstr("Main >> Line variable initialized to '");
	ft_putstr(line);
	ft_putstr("'\n");
	printf("Main >> Address of line is : %p\n", line);
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
	run_gnl(fd, &line);
	ft_putstr("Main >> Closing file...\n");
	if (close(fd) != 0)
	{
		ft_putstr("Main >> Close failed, end of test.\n");
		return (1);
	}
	ft_putstr("Main >> File successfully closed.\n");
/*
	ft_putstr("(TBDel)Main >> Read from stdin test start\n");
	run_read_stdin();
	ft_putstr("(TBDel)Main >> Read from stdin test over\n");
	
	ft_putstr("Main >> Attempting GNL on stdin.\n");
	run_gnl(0, &line);
	ft_putstr("Main >> Test completed, end of program.\n");
*/
	return (0);
}
