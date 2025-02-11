/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 16:21:22 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:03:53 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
// 	// char c = 'a';
// 	// int fd = 2;
// 	ft_putchar_fd('a', 2);
// }