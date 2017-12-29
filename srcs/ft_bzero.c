void	ft_bzero(void *s, int n)
{
	int i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((unsigned char*)s)[i] = '\0';
		i++;
	}
}
