/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:30:38 by sait-alo          #+#    #+#             */
/*   Updated: 2023/12/24 13:30:40 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *content, char *buffer);
static char	*get_rest(char *line);

char	*get_next_line(int fd)
{
	static char	*content;
	char		*buffer;
	char		*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(content);
		buffer = NULL;
		content = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = read_line(fd, content, buffer);
	free(buffer);
	buffer = NULL;
    if (!line)
        return (NULL);
	content = get_rest(line);
	return (line);
}

static char	*read_line(int fd, char *content, char *buffer)
{
	ssize_t	r_char;
	char	*tmp;

	r_char = 1;
	while (r_char > 0)
	{
		r_char = read(fd, buffer, BUFFER_SIZE);
		if (r_char == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		if (r_char == 0)
			break ;
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		if (ft_strchr(content, '\n'))
			break ;
	}
	return (content);
}

static char	*get_rest(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

int main(){

	int fd = open("batman.txt", O_RDWR);

	printf("1st: %s \n", get_next_line(fd));
	printf("2nd (SHOULD RETURN NULL): %s", get_next_line(fd));
}