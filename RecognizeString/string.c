/**
 *  Author     : abhijithvijayan
 *  Created on : 26 Nov 19, 07:27
 *  Title      : Pattern Recognizer
 *  Aim        : Identify which pattern a string belongs to
 */

#include <stdio.h>
#include <string.h>

int checkIfStringAccepted(char str[])
{
  int i;
  int flag;
  int len = strlen(str);

  for (i = 0; i < len; i++)
  {
    // Rule a*
    if ((str[0] == 'a') && (str[i] == 'a') && (flag != 3))
    {
      flag = 1;
    }
    // Rule abb
    else if ((str[0] == 'a') && (str[1] == 'b') && (str[2] == 'b') && (len == 3))
    {
      flag = 2;
    }
    // Rule a*b+
    else if (str[i] == 'b')
    {
      flag = 3;
    }
    else
    {
      flag = 0;
      break;
    }
  }

  return flag;
}

int main()
{
  char str[20];

  printf("Enter a string: ");
  scanf("%[^\n]", str);

  int flag = checkIfStringAccepted(str);

  if (flag == 1)
  {
    printf("\n`%s` is accepted under rule a*\n", str);
  }
  else if (flag == 2)
  {
    printf("\n`%s` is accepted under rule abb\n", str);
  }
  else if (flag == 3)
  {
    printf("\n`%s` is accepted under rule a*b+\n", str);
  }
  else
  {
    printf("\n`%s` is not recognised.\n", str);
  }

  return 0;
}