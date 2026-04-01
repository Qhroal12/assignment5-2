#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int main() {

	int arr[N][N] = { 0, };

	int a = N / 2; //가로
	int b = 0;	   //세로	

	arr[a][b] = 1;

	int ToN = arr[a][b];

	while (ToN != N * N) {

		if (arr[(a + 1 + N) % N][(b - 1 + N) % N] != 0) { //다음 위치에 숫자가 있을 시
			b = (b + 1 + N) % N;
			arr[a][b] = ++ToN;
		}
		else {											 
			a = (a + 1 + N) % N;
			b = (b - 1 + N) % N;
			arr[a][b] = ++ToN;
		}

	}

	///////////////////////////////////////배열 출력///////////////////////////////////////////////


	for (int i = 0; i < N; i++) {

		int width = 0;
		int height = 0;
		int leftdia = 0;
		int rightdia = 0;

		for (int j = 0; j < N; j++) {

			width += arr[j][i]; 
			height += arr[i][j];
			leftdia += arr[j][j];
			rightdia += arr[N - (j + 1)][N - (j + 1)];

			if (arr[j][i] < 10) {
				printf("0");
				printf("%d ", arr[j][i]);
			}
			else
				printf("%d ", arr[j][i]);
		}
		printf("  %d", width);

		printf("\n");

		if (i == (N - 1)) {
			printf("\n");
			for (int j = 0; j < N; j++) {
				printf("%d ", height);
			}

			printf("		leftdia = %d, rightdia = %d", leftdia, rightdia);
		}
		
	}

	return 0;
}
