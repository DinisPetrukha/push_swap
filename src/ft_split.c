/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:16:47 by dpetrukh          #+#    #+#             */
/*   Updated: 2023/12/31 14:27:09 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str, char separator)
{
	int	count_words;
	int	bool_word;

	count_words = 0;
	while (*str)
	{
		bool_word = 0;
		while (*str && *str == separator)
			str++;
		while (*str && *str != separator)
		{
			if (!bool_word)
			{
				count_words += 1;
				bool_word = 1;
			}
			str++;
		}
	}
	return (count_words);
}

char	*get_next_word(char *str, char separator)
{
	int			len;
	int			i;
	static int	base;
	char		*next_word;

	i = 0;
	len = 0;
	while (str[base] && str[base] == separator)
		base++;
	while (str[base + len] && str[base + len] != separator)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (str[base] && str[base] != separator)
		next_word[i++] = str[base++];
	next_word[i++] = '\0';
	return (next_word);
}

char	**ft_split(char *argv, char separator)
{
	int		i;
	int		words_number;
	char	**vector;

	i = 0;
	words_number = count_words(argv, separator);
	vector = malloc(sizeof(char *) * (words_number + 2));
	if (vector == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (i == 0)
		{
			vector[i] = malloc(sizeof(char));
			if (NULL == vector[i])
				return (NULL);
			vector[i++][0] = '\0';
		}
		else
			vector[i++] = get_next_word(argv, separator);
	}
	vector[i] = NULL;
	return (vector);
}
