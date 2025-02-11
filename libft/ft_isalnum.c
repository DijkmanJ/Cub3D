/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:53:06 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 16:14:44 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (8);
	else
		return (0);
}

// int main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isalnum(i) != isalnum(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isalnum(i));
// 			printf("%i\n", isalnum(i));
// 			continue;
// 		}
// 		printf("ok ");
// 	}
// }