/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday04-timothe.coniel
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
  int a;
  int b;

  a = 0;
  b = 0;
  if (str[0] && str[0] == '-')
    a++;
  while (str[a])
    {
      if ((str[a] < '0' || str[a] > '9'))
    return (0);
      b = b + str[a] - 48;
      b = b * 10;
      a++;
    }
  b = b / 10;
  if (str[0] == '-')
    return (-1 * b);
  else
    return (b);
}