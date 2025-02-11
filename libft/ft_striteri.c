/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdijkman <jdijkman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 15:51:56 by jdijkman      #+#    #+#                 */
/*   Updated: 2023/10/23 17:10:34 by jdijkman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || ! f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i ++;
	}
}

// void func(unsigned int i, char *str)
// {
// 	while (i > 0)
// 	{
// 		str[i] = str[i] - 32;
// 		i --;
// 	}
// 	return (str);
// }

// int main(void)
// {
// 	char *s = "hello";
// 	unsigned int i = 4;
// 	ft_striteri(s, f(s, func));
// }