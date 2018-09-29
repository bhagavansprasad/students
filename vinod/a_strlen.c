int a_strlen(const char *src)
{
	int i = 0;

	for(i = 0; src[i]; i++);

	return i;
}
