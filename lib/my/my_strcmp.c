/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;
    int b;
    int res;

    for (; s1[a] == s2[b] && s1[a] != '\0' && s2[b] != '\0'; a += 1) {
        b +=1;
    }
    if (s1[a] < s2[b])
        res = 1;
    else if (s1[a] > s2[b])
        res = -1;
    else
        res = 0;
    return(res);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      else if (s1[i] < s2[i])
	return (s1[i] - s2[i]);
      else
	++i;
    }
  return (0);
}