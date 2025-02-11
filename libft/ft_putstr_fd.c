/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 16:31:50 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:07:43 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i ++;
	}
}

// int main(void)
// {
// 	char *s = "hello world"; 
// 	int fd = 0; 
// 	ft_putstr_fd(s, fd);
// }