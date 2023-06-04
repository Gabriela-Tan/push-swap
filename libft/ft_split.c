/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:52:32 by gabtan            #+#    #+#             */
/*   Updated: 2023/05/30 10:11:57 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char delimiter)
{
	int	i;
	int	word_count;
	int	prev_is_delimiter;

	i = 0;
	word_count = 0;
	prev_is_delimiter = 1;
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
		{
			prev_is_delimiter = 1;
		}
		else if (prev_is_delimiter)
		{
			word_count++;
			if (str[i] != delimiter)
				prev_is_delimiter = 0;
		}
		i++;
	}
	return (word_count);
}

static int	ft_wordlen(char const *str, char delimiter, int index)
{
	int	size;

	size = 0;
	while (str[index] != delimiter && str[index])
	{
		size++;
		index++;
	}
	return (size);
}

static char	ft_free(char **str_arr, int index)
{
	while (index > 0)
	{
		index--;
		free(str_arr[index]);
	}
	free(str_arr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = 0;
	words = ft_count_word(s, c);
	strs = (char **)malloc((words + 1) * sizeof(char *));
	if (!(strs))
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		size = ft_wordlen(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!(strs[j]))
			ft_free(strs, j);
		i = i + size;
		j++;
	}
	strs[j] = 0;
	return (strs);
}
