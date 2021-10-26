#include <stdio.h>
#pragma warning(disable:4996) 
int to_bin(int n);
int count_to_bin(int n, int* zero_count);
int main(void) {
	int number=0;
	while (1)
	{
		printf("Input num: ");
		scanf("%d", &number);
		if (number == -1)
			break;
		int zero_count = 0;
		printf("2진 표현: ");
		to_bin(number);
		count_to_bin(number, &zero_count);
		printf("\n%d내 0은 %d개 있다.",number, zero_count);
		printf("\n");
	}
	printf("Exit");
	return 0;
}

int to_bin(int n) {
	if (n == 0 || n == 1)
	{
		printf("%d", n);
	}
	else {
		to_bin(n / 2);

		printf("%d", n % 2);
	}
	return 0;
}
int count_to_bin(int n, int* zero_count) {
	if (n == 0 || n == 1)
	{
		if (n == 0)
			*zero_count = (*zero_count) + 1;
	}
	else {
		count_to_bin(n / 2, zero_count);
		if (n % 2 == 0)
			*zero_count = (*zero_count) + 1;
	}
	return 0;
}