/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:27:47 by amulin            #+#    #+#             */
/*   Updated: 2015/02/10 16:30:43 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int	gnl_loop(int fd, char **line)
{
	while (get_next_line(fd, line))
		ft_putendl(*line);
	if (get_next_line(0, line) == -1)
	{
		ft_putstr("Main >> GNL returned 0, read over\n");
		return (0);
	}
	if (get_next_line(0, line) == -1)
	{
		ft_putstr("Main >> GNL returned -1, error\n");
		return (1);
	}
	return (0);
}

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
		ft_putstr(", returns 1, line = \t'");
		ft_putstr(*line);
		ft_putstr("'\n");
		ret = get_next_line(fd, line);
		i++;
	}
	if (ret == 0)
	{
		ft_putstr("Main >> GNL run ");
		ft_putnbr(i);
		ft_putstr(", returns 0, line = \t'");
		ft_putstr(*line);
		ft_putstr("'\n");
		ft_putstr("Main >> GNL returned 0, read over\n");
	}
	if (ret == -1)
	{
		ft_putstr("Main >> GNL returned -1, error\n");
		return (1);
	}
	return (0);
}

int	run_gnl_stdin(char **line)
{
	ft_putstr("Main >> Running GNL from stdin.\n");
	ft_putstr("     >>> Type 'quit' to end program.\n");
	ft_putstr("     >>> Type 'control-v control-j' to write an end-of-line.\n");
	while (get_next_line(0, line))
	{
		if (!ft_strcmp(*line, "quit"))
			return (0);
		ft_putendl(*line);
	}
	if (get_next_line(0, line) == -1)
	{
		ft_putstr("Main >> GNL returned 0, read over\n");
		return (0);
	}
	if (get_next_line(0, line) == -1)
	{
		ft_putstr("Main >> GNL returned -1, error\n");
		return (1);
	}
	return (0);
}

int file_opening(char *str, int *fd)
{
	ft_putstr("Main >> Opening file '");
	ft_putstr(str);
	ft_putstr("'...\n");
	*fd = open(str, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr("Main >> Open fail, end of test.\n");
		return (1);
	}
	ft_putstr("Main >> File successfully opened on fd = ");
	ft_putnbr(*fd);
	ft_putchar('\n');
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

//	line = ft_strnew(BUFF_SIZE);
	line = "Hello";
	i = 1;
	if (argc == 1)
	{
		ft_putstr("Main >> Error : Please enter a parameter.\n");
		ft_putstr("     >>> Help : Try 'file_name' to read from a file, or 'stdin' from standard input.\n");
		ft_putstr("     >>> Example : ./test_gnl fichier0\n");
	}
	else if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "stdin"))
			run_gnl_stdin(&line);
		else 
		{
			if (file_opening(argv[1], &fd))
				return (1);
			run_gnl(fd, &line);
			ft_putstr("Main >> Closing file...\n");
			if (close(fd) != 0)
			{
				ft_putstr("Main >> Close failed, end of test.\n");
				return (1);
			}
			ft_putstr("Main >> File successfully closed.\n");
			i++;
		}
	}
	else
	{
		while (i < argc)
		{
			if (file_opening(argv[i], &fd))
				return (1);
			run_gnl(fd, &line);
			ft_putstr("Main >> Closing file...\n");
			if (close(fd) != 0)
			{
				ft_putstr("Main >> Close failed, end of test.\n");
				return (1);
			}
			ft_putstr("Main >> File successfully closed.\n");
			i++;
		}
	}
	ft_putstr("Main >> All fine, end of test.\n");
	return (0);
}
