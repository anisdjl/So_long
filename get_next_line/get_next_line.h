/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:38:11 by adjelili          #+#    #+#             */
/*   Updated: 2025/12/04 09:40:52 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *stash, char const *buffer);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
int		ft_test_n(char *stash);
char	*ft_line(char *stash);
char	*ft_substr(char *stash, unsigned int start, size_t len);
char	*ft_update_stash(char *stash);
char	*ft_strdup(char *s);
char	*read_and_fill(int fd, char *stash);

#endif