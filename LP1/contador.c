#include <stdio.h>
main()
{
	int tab=0,emb=0,lin=0;
	char c;
	while ((c=getchar())!=EOF)
	{
		if (c==' ')
			emb+=1;
		if (c=='\t')
			tab+=1;
		if (c=='\n')
			lin+=1;
	}
	printf("\nQuantidade de espa�os: %d\nQuantidade de linhas: %d\nQuantidade de tabula��es: %d",emb,tab,lin);
}
