/*  strindex: выдает позицию самого правого вхождения строки t в строку s
  или -1, если вхождения не обнаружено */

int strindex(char s[], char t[])
{
    int i, j, k;
    int right_index = -1;

    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k);

        if (k > 0 && t[k] == '\0')
            right_index = i;
    }

    return (right_index != -1) ? right_index : -1;
}
