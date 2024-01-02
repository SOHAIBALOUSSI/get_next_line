/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:30:47 by sait-alo          #+#    #+#             */
/*   Updated: 2023/12/24 13:30:50 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);

size_t		ft_strlen(const char *s);
int			ft_strchr(const char *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
