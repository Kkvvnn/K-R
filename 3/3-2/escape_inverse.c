/*  escape_inverse: копирует t в s, преобразуя эскейп-последовательности
    в настоящие символы */
void escape_inverse(char s[], char t[])
{
    int i, j;
    int slash = 0;          /* slash = 1 - введен обратный слеш (\)*/
    
    for (i = 0, j = 0; t[i] != '\0'; ++i, ++j)
        switch (t[i])
        {
            case '\\': slash = 1;
                       --j;
                       break;

            case 'n': if (slash)
                      {
                          s[j] = '\n';
                          slash = 0;
                      }
                      break;

            case 't': if (slash)
                      {
                          s[j] = '\t';
                          slash = 0;
                      }
                      break;

            default: s[j] = t[i];
                     break;
        }
    s[j] = '\0';

}

