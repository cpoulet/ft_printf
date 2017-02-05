/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:34:57 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/24 10:30:56 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_stock(t_file **file, char *p_n)
{
	char	*tmp;

	if (p_n)
	{
		(*file)->excess = ft_strdup(p_n + 1);
		tmp = (*file)->buffer;
		(*file)->buffer = ft_strsub(tmp, 0, p_n - tmp);
		ft_strdel(&tmp);
	}
	else if ((tmp = ft_strchr((*file)->buffer, '\n')))
	{
		tmp = (*file)->buffer;
		(*file)->buffer = ft_strsub(tmp, 0, ft_strlen(tmp) - 1);
		ft_strdel(&tmp);
	}
}

static	void	ft_excess(t_file **file)
{
	char *tmp;

	if ((*file)->excess)
	{
		tmp = (*file)->buffer;
		(*file)->buffer = ft_strjoin((*file)->excess, (*file)->buffer);
		ft_strdel(&tmp);
		ft_strdel(&(*file)->excess);
	}
}

static int		readline(t_file **file)
{
	int		ret;
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = ft_strnew(BUFF_SIZE);
	if (!(*file)->buffer)
		(*file)->buffer = ft_strnew(BUFF_SIZE);
	ft_excess(file);
	while (tmp == NULL && (ret = read((*file)->fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = (*file)->buffer;
		(*file)->buffer = ft_strjoin((*file)->buffer, buff);
		ft_strdel(&tmp);
		ft_strclr(buff);
		tmp = ft_strchr((*file)->buffer, '\n');
	}
	tmp = ft_strchr((*file)->buffer, '\n');
	ft_strdel(&buff);
	if (ret == -1)
		return (-1);
	if (!*((*file)->buffer))
		return (0);
	ft_stock(file, tmp);
	return (1);
}

static t_file	*select_struct(const int fd, t_file **file)
{
	t_file	*elem;
	t_file	*svg;

	svg = (*file)->start;
	*file = svg;
	while ((*file)->next && (*file)->fd != fd)
		*file = (*file)->next;
	if ((*file)->fd == fd)
		return (*file);
	elem = (t_file*)malloc(sizeof(t_file));
	(*file)->next = elem;
	elem->fd = fd;
	elem->start = svg;
	elem->buffer = NULL;
	elem->excess = NULL;
	elem->next = NULL;
	return (elem);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_file	*file = NULL;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!file)
	{
		file = (t_file*)malloc(sizeof(t_file));
		file->fd = fd;
		file->excess = NULL;
		file->buffer = NULL;
		file->start = file;
		file->next = NULL;
	}
	if (file->fd != fd)
		file = select_struct(fd, &file);
	ret = readline(&file);
	*line = ft_strdup(file->buffer);
	ft_strdel(&file->buffer);
	return (ret);
}
