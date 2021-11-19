#include"dict-header.h"
#include "dict-soundex.h"
#include <string.h>
//----------------------------------------------------------
typedef struct {
	char data[256];
} cache;
//----------------------------------------------------------
BTA *dictOpen(BTA *root, char *dict)
{
	root = btopn(dict, 0, 0);
	if (root == NULL)
		root = btcrt(dict, 0, 0);	
	return root;
}
//----------------------------------------------------------
// Insert
void dictInsert(BTA *root, char *engWord, char *vietWord, int *dsize)
{
	int check;
	check = btins(root, engWord, vietWord, *dsize);
	
	if (check == 0)
		printf("Insert successfully!\n");
	else
		printf("Some errors occur while inserting!\n");
	
	return;
}
//------------------------------------------------------------
void dictUpdate(BTA *root, char *engWord, char *vietWord, int *dsize, int *rsize)
{
	init();
	int check;
	check = btupd(root, engWord, vietWord, *dsize);
	if (check == 0)
		printf("Update successfully!\n");
	else
	{
		char dictWord[256];
		char a[256];
		strcpy(a, soundex(engWord));

		if (btpos(root, 1) != 0)
		{
			printf("The dictionary is blank!\n");
			return;
		}

		printf("Do you mean:\n");
		int i = 0;
		cache cacheStorage[100];
		char vietWordTemp[256];
		while (btseln(root, dictWord, vietWordTemp, *dsize, rsize) == 0)
		{	
			char b[256];
			strcpy(b, soundex(dictWord));

			if (strcmp(a, b) == 0)
			{
				strcpy(cacheStorage[i].data, dictWord);
				i++;
				printf("\t%d:\t%s\n", i, dictWord);
			}
		}

		int choice;
		printf("Your choice: ");
		scanf("%d", &choice);
		int j = 0;
		for (; j < i; j++)
		{
			if (choice == j+1)
			{
				dictUpdate(root, cacheStorage[j].data, vietWord, dsize, rsize);
				return;
			}
		}
		printf("Some errors occur while updating!\n");
	}
}
//------------------------------------------------------------
void dictSearch(BTA *root, char *engWord, char *vietWord, int dsize, int *rsize, int pos)
{
	init();
	if (btsel(root, engWord, vietWord, dsize, rsize) == 0)
		printf("Finding successfully!\nTranslation:\t%s\t-->\t%s\n", engWord, vietWord);
	else
	{
		char dictWord[256];
		char a[256];
		strcpy(a, soundex(engWord));

		if (btpos(root, pos) != 0)
		{
			printf("The dictionary is blank!\n");
			return;
		}

		printf("Do you mean:\n");
		int i = 0;
		cache cacheStorage[100];
		while (btseln(root, dictWord, vietWord, dsize, rsize) == 0)
		{	
			char b[256];
			strcpy(b, soundex(dictWord));

			if (strcmp(a, b) == 0)
			{
				strcpy(cacheStorage[i].data, dictWord);
				i++;
				printf("\t%d:\t%s\n", i, dictWord);
			}
		}

		int choice;
		printf("Your choice: ");
		scanf("%d", &choice);
		int j = 0;
		for (; j < i; j++)
		{
			if (choice == j+1)
			{
				dictSearch(root, cacheStorage[j].data, vietWord, dsize, rsize, 1);
				return;
			}
		}

		printf("Cannot find the word in the dictionary. Please try again!\n");
		return;
	};
}
//----------------------------------------------------------
void dictDeleteNode(BTA *root, char *engWord, char *vietWord, int dsize, int *rsize)
{
	init();
	if (btdel(root, engWord) == 0)
		printf("Delete successfully!\n");
	else
	{
		char dictWord[256];
		char a[256];
		strcpy(a, soundex(engWord));

		if (btpos(root, 1) != 0)
		{
			printf("The dictionary is blank!\n");
			return;
		}

		printf("Do you mean:\n");
		int i = 0;
		cache cacheStorage[100];
		while (btseln(root, dictWord, vietWord, dsize, rsize) == 0)
		{	
			char b[256];
			strcpy(b, soundex(dictWord));

			if (strcmp(a, b) == 0)
			{
				strcpy(cacheStorage[i].data, dictWord);
				i++;
				printf("\t%d:\t%s\n", i, dictWord);
			}
		}

		int choice;
		printf("Your choice: ");
		scanf("%d", &choice);
		int j = 0;
		for (; j < i; j++)
		{
			if (choice == j+1)
			{
				dictDeleteNode(root, cacheStorage[j].data, vietWord, dsize, rsize);
				return;
			}
		}

		printf("Some errors occur while deleting!\n");
		return;
	}
}
//----------------------------------------------------------
void dictPrint(BTA *root, char *engWord, char *vietWord, int pos, int dsize, int *rsize)
{
	if (btpos(root, pos) != 0)
	{
		printf("\nThe dictionary is blank!\n");
		return;
	}
	printf("\n----------DICTIONARY----------\n"); 
	printf("English\t\t\tVietnamese\n");
	while (btseln(root, engWord, vietWord, dsize, rsize) == 0)
		printf("%s\t\t\t%s\n", engWord, vietWord);
	printf("------------------------------\n\n");

	return;
}
//----------------------------------------------------------
void dictDeleteAll(BTA *root, char *engWord, char *vietWord, int pos, int dsize, int *rsize)
{
	int check;

	if (btpos(root, pos) != 0)
	{
		printf("The dictionary is blank!\n");
		return;
	}
	while (btseln(root, engWord, vietWord, dsize, rsize) == 0)
		check = btdel(root, engWord);
	if (check == 0)
	{
		printf("Delete successfully!\n");
	}
	else
		printf("Some errors occur while deleting!\n");

	return;
}
//----------------------------------------------------------
void menu()
{
	printf("\n====================MENU====================\n");
	printf("0, Exit\n");
	printf("1, Read the database from a text file\n");
	printf("2, Insert a new word\n");
	printf("3, Update a word in the dictionary\n");
	printf("4, Search for a word\n");
	printf("5, Delete a word\n");
	printf("6, Print the dictionary\n");
	printf("7, Delete the dictionary\n");
	printf("============================================\n\n");
}
//----------------------------------------------------------
