#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"inc/btree.h"
//----------------------------------------------------------
BTA *dictOpen(BTA *root, char *dict);
void dictInsert(BTA *root, char *engWord, char *vietWord, int *dsize);
void dictUpdate(BTA *root, char *engWord, char *vietWord, int *dsize);
void dictDeleteNode(BTA *root, char *engWord);
void dictSearch(BTA *root, char *engWord, char *vietWord, int dsize, int *rsize, int pos);
void dictPrint(BTA *root, char *engWord, char *vietWord, int pos, int dsize, int *rsize);
void dictDeleteAll(BTA *root, char *engWord, char *vietWord, int pos, int dsize, int *rsize);
void menu();
