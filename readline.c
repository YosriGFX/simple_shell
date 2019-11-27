#include "shell.h"
/**
 * readline - readline function
 *
 * Return: char
 */
char *readline(void)
{
char *nom = getenv("_");
int bufsize = BUFSIZE;
int idx = 0;
char *buff = malloc(sizeof(char) * bufsize);
int c;
_puts("#cisfun$ ");
if (!buff)
{
perror(nom);
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c == EOF)
{
exit(0);
}
else if (c == '\n')
{
buff[idx] = '\0';
return (buff);
}
else
{
buff[idx] = c;
}
idx++;
if (idx >= bufsize)
{
bufsize += BUFSIZE;
buff = realloc(buff, bufsize);
if (!buff)
{
perror(nom);
exit(EXIT_FAILURE);
}
}
}
}
