#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int mod(int b, int e, int m) {
	char a[30];
	int i = 0;
	while (e != 0) {
		a[i] = e % 2;
		e /= 2;
		i++;
	}
	unsigned long long x = 1;
	unsigned long long power = b % m;
	for (int j = 0; j < i; j++) {
		if (a[j] == 1)
			x = (x * power) % m;
		power = (power * power) % m;
	}
	return x;
}

void main1() {
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	unsigned long long p, q, n, e;
	fscanf(input,"%llu\n%llu\n%llu\n%llu\n", &p, &q, &n, &e);
	char s[1000];
	int i = 0;
	repeat:
	fscanf(input,"%c", &s[i]);
	if (s[i] != '\n' && s[i] != EOF) {
		if ((s[i] <= 'z' && s[i] >= 'a'))
			i++;
		goto repeat;
	}
	for (int j = 4 - (i % 4); j > 0; j--) {
		if (j == 4)
			break;
		else
			s[i++] = 'z';
	}
	int *si = (int*)malloc(sizeof(int)* (i / 4));
	for (int j = 0; j < i / 4; j++) {
		*(si + j) = 0;
		for (int k = 0; k < 4; k++) {
			*(si + j) *= 100;
			*(si + j) += (s[j * 4 + k] - 'a');
		}
	}
	for (int j = 0; j < i / 4; j++) {
		printf("%d ", *(si + j));
	}
	printf("\n");
	for (int j = 0; j < i / 4; j++) {
		*(si + j) = mod(*(si + j), e, n);
	}
	//test
	//printf("%d",mod(3, 644, 645));
	//test
	for (int j = 0; j < i/ 4; j++) {
		char *temp = (char*)malloc(sizeof(char)* 8);
		sprintf(temp, "%d", *(si + j));
		int digits = strlen(temp);
		for (int k = digits; k < 8; k++) {
			fprintf(output,"0");
		}
		fprintf(output,"%d", *(si + j));

	}
	

	system("pause");
}