#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i - 1] != '\n')
		i++;
	return (i);
}


char	*ft_nljoin(char *s1, char *s2)
{
	 char	*out;
	 int	i;
	 int	j;

	 out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	 i = 0;
	 while (s1[i])
	 {
		out[i] = s1[i];
		i++;
	 }
	 j = 0;
	 while (s2[j] && s2[j - 1] != '\n')
	 {
		out[i] = s2[j];
		j++;
		i++;
	 }
	 out[i] = '\0';
	 return (out);
}

int	main()
{
	char	*s1 = "Wesh ";
	char	*s2 = "l'equipe\nzer !";
	char	*s3;

	s3 = ft_nljoin(s1, s2);
	printf("yo");
	printf("%s", s3);
	free(s3);
	return  (1);
}
