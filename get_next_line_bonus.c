/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 09:07:29 by sait-alo          #+#    #+#             */
/*   Updated: 2024/01/01 09:07:32 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *content, char *buffer)
{
	ssize_t	readed;
	char	*tmp;

	readed = 1;
	while (readed > 0 && !(ft_strchr(content, '\n')))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (readed == 0)
			break ;
		if (!content)
			content = ft_strdup("");
		buffer[readed] = '\0';
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
	}
	free(buffer);
	return (content);
}

static char	*get_rest(char *line)
{
	ssize_t	i;
	char	*result;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*result == 0)
	{
		free(result);
		result = NULL;
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*content[MAX_FD];
	char		*buffer;
	char		*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_line(fd, content[fd], buffer);
	if (!line)
		return (NULL);
	content[fd] = get_rest(line);
	return (line);
}
