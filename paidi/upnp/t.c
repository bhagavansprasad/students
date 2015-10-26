#include "stdio.h"
#include "string.h"

char buff[] = "<item id=\"218\" parentID=\"216\" restricted=\"1\"><dc:title>lifeisbeautiful.mp4</dc:title>";

int get_tag_value_by_tag_name(char *buff, char *needle, char schar, char echar, char *rbuff)
{
	char *t = strstr(buff, needle);
	int i = 0, j = 0;

	printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != schar; i++);
		printf("-->i :%d, t :%s\n", i, &t[i]);

		i++;
		for (j = 0 ; t[i] != echar; i++, j++)
			rbuff[j] = t[i];

		rbuff[j] = '\0';

		printf("-->j :%d, id_value :%s\n", i, rbuff);;
	}
}

int get_tag_value( char *buff, char *needle, char schar, char echar, char *rbuff)
{
	int i = 0, j = 0;
	char *t = strstr(buff, needle);

	//printf("-->t :%s\n", t);

	if (t != NULL)
	{
		for (i = 0; t[i] != schar; i++);
		i++;
		//printf("-->i :%d, t :%s\n", i, &t[i]);

		for (j = 0 ; t[i] != echar; i++, j++)
			rbuff[j] = t[i];

		rbuff[j] = '\0';;

		//printf("-->i :%d, t        :%s\n", i, &t[i]);
		//printf("-->j :%d, rbuff    :%s\n", i, rbuff);;
	}
}

main()
{
	int i = 0, j = 0;
	char *t;
	char id_value[100];
	char parent_id[100];
	char restricted[100];
	char title[100];
	int id;

	get_tag_value_by_tag_name(buff, "id=", '"', '"', id_value);
	id = atoi(id_value);
	get_tag_value_by_tag_name(buff, "parentID=", '"', '"', parent_id);
	get_tag_value_by_tag_name(buff, "restricted=", '"', '"', restricted);
	get_tag_value_by_tag_name(buff, "title", '>', '<', title);
#if 0
	get_tag_value(buff, "restricted=", '=', '>', restricted);
	get_tag_value(buff, "title", '>','<', title);
#endif

	printf("-->id_value   :%s\n", id_value);
	printf("-->parent id  :%s\n", parent_id);
	printf("-->restricted :%s\n", restricted);
	printf("-->title      :%s\n", title);
	return 0;

	t = strstr(buff, "id=");
	printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != '='; i++);
		i++;
		i++;
		printf("-->i :%d, t :%s\n", i, &t[i]);

		for (j = 0 ; t[i] != '"'; i++, j++)
			id_value[j] = t[i];

		id_value[j] = '\0';

		printf("-->i :%d, t        :%s\n", i, &t[i]);
		printf("-->j :%d, id_value :%s\n", i, id_value);;
	}

	t = strstr(buff, "parentID=");
	printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != '='; i++);
		i++;
		i++;
		printf("-->i :%d, t :%s\n", i, &t[i]);

		for (j = 0 ; t[i] != '"'; i++, j++)
			id_value[j] = t[i];

		id_value[j] = '\0';

		printf("-->i :%d, t        :%s\n", i, &t[i]);
		printf("-->j :%d, id_value :%s\n", i, id_value);;
	}

	t = strstr(buff, "restricted=");
	printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != '='; i++);
		i++;
		i++;
		printf("-->i :%d, t :%s\n", i, &t[i]);

		for (j = 0 ; t[i] != '"'; i++, j++)
			id_value[j] = t[i];

		id_value[j] = '\0';

		printf("-->i :%d, t        :%s\n", i, &t[i]);
		printf("-->j :%d, id_value :%s\n", i, id_value);;
	}

//"<item id=\"218\" parentID=\"216\" restricted=\"1\"><dc:title>lifeisbeautiful.mp4</dc:title>";
	t = strstr(buff, "title");
	printf("-->t :%s\n", t);
	if (t != NULL)
	{
		for (i = 0; t[i] != '>'; i++);
		printf("-->i :%d, t :%s\n", i, &t[i]);

		i++;
		for (j = 0 ; t[i] != '<'; i++, j++)
			id_value[j] = t[i];

		id_value[j] = '\0';

		printf("-->i :%d, t        :%s\n", i, &t[i]);
		printf("-->j :%d, id_value :%s\n", i, id_value);;
	}

}


