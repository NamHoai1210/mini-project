#include "dict-soundex.h"
#include <string.h>
#include <stdio.h>

int main() {
	init();
	printf("%s", soundex("Javascript"));
	char a[256], b[256];
	strcpy(a, soundex("dick"));
	strcpy(b, soundex("desk"));
	printf("\n%s %s\n", a, b);
}
