/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmago <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:22:14 by mmago             #+#    #+#             */
/*   Updated: 2022/03/08 14:22:22 by mmago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/fcntl.h>
# include <stdio.h>
# include <stdlib.h>

void	error(void);
void	child_process(char **av, char **envp, int *fd);
void	parent_process(char **av, char **envp, int *fd);
int		main(int ac, char **av, char **envp);
char	**ft_split(char const *s, char c);
void	execute(char *av, char **envp);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
char	*find_path(char *command, char **envp);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_substr(char const *s, int start, size_t len);

#endif
