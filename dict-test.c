#include"dict-header.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
//--------------------------------------------------------
int main()
{
	char test[] = "dict-test.db";
	BTA *dictTest;
	int dsize = 256;
	int rsize;
	char engWord[256];
	char vietWord[256];
	int choice = -1;

	btinit();
	dictTest = dictOpen(dictTest, test);

	while(1)
	{
		if (choice == 0) break;

		printf("\n====================MENU====================\n0, End test\n1, Create random words and Insert\n2, Read the database and Insert\n3, Search for a word\n4, Print\n");
		printf("============================================\n\n");
		printf("Your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 0:
			{
				btcls(dictTest);
				break;
			}

			case 1:
			{
				printf("Start inserting! Please wait!\n...");
				int index = 2000000;
				srand(time(NULL));

				struct timeval tv1, tv2;
				gettimeofday(&tv1, NULL);
				while(index)
				{
					int len1 = rand() % 6 + 1;
					engWord[len1] = 0;
					while(len1)
						engWord[--len1] = 'a' + rand() % 26;

					int len2 = rand() % 6 + 1;
					vietWord[len2] = 0;
					while(len2)
						vietWord[--len2] = 'a' + rand() % 26;

					btins(dictTest, engWord, vietWord, dsize);

					index--;
				}
				gettimeofday(&tv2, NULL);

				if (index == 0)
					printf("\nFinished!\n");
				else
					printf("Errors!\n");
				printf("Total time: %lf\n", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec));
				break;
			}
			case 2:
			{
				char path[256];
				printf("Insert file name: ");
				scanf("%s", path);
				FILE *fi = fopen(path , "r");

				struct timeval tv1, tv2;
				gettimeofday(&tv1, NULL);
				while(1)
				{
					fscanf(fi , "%s %s\n", engWord, vietWord);
					btins(dictTest, engWord, vietWord, dsize);
					if (feof(fi))
						break;
				}
				gettimeofday(&tv2, NULL);

				printf("Read the database successfully!\n");
				printf("Total time: %lf\n", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec));

				fclose(fi);
				break;
			}
			case 3:
			{
				printf("Input: ");
				scanf("%s", engWord);

				struct timeval tv1, tv2;
				gettimeofday(&tv1, NULL);
				dictSearch(dictTest, engWord, vietWord, dsize, &rsize, 1);
				gettimeofday(&tv2, NULL);
				printf("Total time: %lf\n", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec));

				break;
			}
			case 4:
			{
				struct timeval tv1, tv2;
				gettimeofday(&tv1, NULL);
				dictPrint(dictTest, engWord, vietWord, 1, dsize, &rsize);
				gettimeofday(&tv2, NULL);
				printf("Total time: %lf\n", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double)(tv2.tv_sec - tv1.tv_sec));

				break;
			}
		}

	}
}
