函数expand(char *s ,char *t) 在将字符串s复制到字符串t时，将其中的换行符
和制表符转换为可见的转义字符，即用"\n"表示换行符，用"\t"表示制表符。
void expand(char* s, char* t)
{
	int i = 0, j = 0;
	for (i = 0,j = 0; s[i] != '\0'; i++)
	{
		switch (s[i]) {
		        case'\n':t[j++] = '\\';
				         t[j++] = 'n';
				         break;
				case'\t': t[j++] = '\\';
					      t[j++] = 't';
					      break;
				default: t[j++] = s[i];
					     break;
		}
	}
	t[j] = '\0';
}
