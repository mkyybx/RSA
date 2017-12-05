#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long mod(long b, long e, long m) {
	char a[30];
	long i = 0;
	while (e != 0) {
		a[i] = e % 2;
		e /= 2;
		i++;
	}
	unsigned long long x = 1;
	unsigned long long power = b % m;
	for (long j = 0; j < i; j++) {
		if (a[j] == 1)
			x = (x * power) % m;
		power = (power * power) % m;
	}
	return x;
}

void main() {
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	long p, q, n, e;
	fscanf(input, "%ld\n%ld\n%ld\n%ld\n", &p, &q, &n, &e);
	char s[100000];
	long i = 0;
repeat:
	fscanf(input, "%c", &s[i]);
	if (s[i] != '\n' && s[i] != EOF) {
		if ((s[i] <= 'z' && s[i] >= 'a'))
			i++;
		else if ((s[i] <= 'Z' && s[i] >= 'A')) {
			s[i] += ('a' - 'A');
			i++;
		}
		goto repeat;
	}
	for (long j = 4 - (i % 4); j > 0; j--) {
		if (j == 4)
			break;
		else
			s[i++] = 'z';
	}
	long *si = (long*)malloc(sizeof(long)* (i / 4));
	for (long j = 0; j < i / 4; j++) {
		*(si + j) = 0;
		for (long k = 0; k < 4; k++) {
			*(si + j) *= 100;
			*(si + j) += (s[j * 4 + k] - 'a');
		}
	}
	for (long j = 0; j < i / 4; j++) {
		printf("%ld ", *(si + j));
	}
	printf("\n");
	for (long j = 0; j < i / 4; j++) {
		*(si + j) = mod(*(si + j), e, n);
	}
	//test
	//printf("%d",mod(3, 644, 645));
	//test
	for (long j = 0; j < i / 4; j++) {
		char *temp = (char*)malloc(sizeof(char)* 8);
		sprintf(temp, "%ld", *(si + j));
		long digits = strlen(temp);
		for (long k = digits; k < 8; k++) {
			fprintf(output, "0");
		}
		fprintf(output, "%ld", *(si + j));

	}


	system("pause");
}