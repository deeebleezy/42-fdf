/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 14:19:15 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/09/26 14:26:16 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_line(char **klay, char **line, int fd, int ret)
{
	char		*tmp;
	int			len;

	len = 0;
	while (klay[fd][len] && klay[fd][len] != '\n')
		len++;
	if (klay[fd][len] == '\n')
	{
		*line = ft_strsub(klay[fd], 0, len);
		tmp = ft_strdup(klay[fd] + len + 1);
		free(klay[fd]);
		klay[fd] = tmp;
	}
	else if (!klay[fd][len])
	{
		if (ret == BUFF_SIZE)
			return (0);
		*line = ft_strdup(klay[fd]);
		free(klay[fd]);
		klay[fd] = NULL;
	}
	return (1);
}

int				ft_get_next_line(const int fd, char **line)
{
	static char	*klay[256];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!klay[fd])
			klay[fd] = ft_strnew(0);
		buf[ret] = '\0';
		tmp = ft_strjoin(klay[fd], buf);
		free(klay[fd]);
		klay[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (!ret && (!klay[fd] || !klay[fd][0]))
		return (0);
	return (read_line(klay, line, fd, ret));
}
