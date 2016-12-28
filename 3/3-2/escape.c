/*  escape: копирует t в s, преобразуя символы новой строки и табуляции в видимые 
    последовательности символов(\n и \t) */
void escape(char s[], char t[])
{
    int i, j;
    
    for (i = 0, j = 0; t[i] != '\0'; ++i, ++j)
        switch (t[i])
        {
            case '\n': s[j++] = '\\';
                       s[j] = 'n';
                       break;
            
            case '\t': s[j++] = '\\';
                       s[j] = 't';
                       break;
            
            default: s[j] = t[i];
                     break;
        }
    s[j] = '\0';
}
