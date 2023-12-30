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

	buffer = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(content);
		free(buffer);
		content = NULL;
		buffer = NULL;
		return (NULL);
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
			return (NULL);
		}
		else if (r_char == 0)
			break ;
		if (!content)
			content = ft_strdup("");
		buffer[r_char] = 0;
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
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

// int main()
// {
//     int fd = open("batman.txt", O_RDONLY);
//     char *line;
// 	int nb = 1;

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line No %d: %s", nb, line);
//         free(line);
// 		line = NULL;
// 		nb++;
//     }
//     close(fd);
//     return (0);
// }