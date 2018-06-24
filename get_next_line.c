/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:22:16 by agardner          #+#    #+#             */
/*   Updated: 2018/06/23 21:00:48 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_nl(char **str, char **line, int fd)
{
    char *temp;
    unsigned int before_nl;

    before_nl = ft_count2delimit_int(str[fd], '\n');
    if (ft_strchr(str[fd], '\n'))
    {
        *line = ft_strsub(str[fd], 0, (size_t)before_nl);
        temp = ft_strsub(str[fd], before_nl + 1, ft_strlen(str[fd]) - before_nl);
        free(str[fd]);
        str[fd] = temp;
        return (1);
    }
    else if (ft_strlen(str[fd]) > 0)
    {
        *line = ft_strdup(str[fd]);
        ft_strdel(&str[fd]);
        return (1);
    }
	return (0);
}

int     get_next_line(char **line, int fd)
{
    static char *str[4096];
    char buf[BUFF_SIZE + 1];
    char *temp;
    int ret;

    if (!line || fd < 0)
        return (-1);
    if (str[fd] == NULL)
        str[fd] = ft_strnew(1);
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        buf[ret] = '\0';
        temp = ft_strjoin(str[fd], buf);
        free(str[fd]);
        str[fd] = temp;
        if ((ft_strchr(str[fd], '\n')))
            break ;
    }
    return(ft_nl(str, line, fd));
}