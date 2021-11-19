#include"dict-header.h"
#include <stdio.h>
//----------------------------------------------------------
int main()
{
	char dict[] = "dict-main.db";
	BTA *dictionary;
	char engWord[256];
	char vietWord[256];
	int dsize = 256;
	int rsize;
	int choice;

	btinit();
	dictionary = dictOpen(dictionary, dict);
	
	while (1)
	{
		if (choice == 0) break;

		menu();
		printf("Your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: // Exit
			{
				btcls(dictionary);
				break;
			}

			case 1: // Read from a File
			{
				char path[256];
				printf("Insert a file name: ");
				scanf("%s", path);
				FILE *fi = fopen(path, "r");

				while(1)
				{
					fscanf(fi, "%s %s\n", engWord, vietWord);
					btins(dictionary, engWord, vietWord, dsize);
					if(feof(fi))
						break;
				}
				printf("Read the database successfully!\n");
				fclose(fi);
				break;
			}

			case 2: // Insert
			{
				printf("Insert an English word: ");
				scanf("%s", engWord);
				printf("Insert its Vietnamese meaning: ");
				scanf("%s", vietWord);

				dictInsert(dictionary, engWord, vietWord, &dsize);
				break;
			}

			case 3: // Update a word
			{
				printf("Insert an English word: ");
				scanf("%s", engWord);
				printf("Insert its Vietnamese meaning: ");
				scanf("%s", vietWord);

				dictUpdate(dictionary, engWord, vietWord, &dsize, &rsize);
				break;
			}


			case 4: // Search
			{
				printf("Insert an English word: ");
				scanf("%s", engWord);
				
				dictSearch(dictionary, engWord, vietWord, dsize, &rsize, 1);
				break;
			}

			case 5: // Delete a word
			{
				printf("Insert an English word: ");
				scanf("%s", engWord);

				dictDeleteNode(dictionary, engWord, vietWord, dsize, &rsize);
				break;
			}

			case 6: // Print the dictionary
			{
				dictPrint(dictionary, engWord, vietWord, 1, dsize, &rsize);
				break;
			}

			case 7: // Delete the dictionary
			{
				dictDeleteAll(dictionary, engWord, vietWord, 1, dsize, &rsize);
				break;
			}
		}
	}
	return 0;
}
//----------------------------------------------------------
