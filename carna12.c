#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 100

void selectionSort (float v[]) {
	int i, posMenorValor = 0, j;
	float temp;
	
	for (i = 0; i < 5 - 1; i++) {
		posMenorValor = i;
		for (j = i + 1; j < 5; j++) {			
			if (v[j] < v[posMenorValor]) {
				posMenorValor = j;
			}
		}
		
		temp = v[i];	
		v[i] = v[posMenorValor];
		v[posMenorValor] = temp;
	}
}
	

int main () {
	
	FILE* fp;
	fp = freopen("input1.txt", "r", stdin);
	
	char buf[LINE_SIZE];
	memset(buf, 0, LINE_SIZE);
	
	if (fp != NULL) {
		fgets(buf, LINE_SIZE, fp);
			
		float notas[5];
		int n, offset;
		
		char * pEnd = NULL;		
		for (n = 0; n < 5; n++) {
			notas[n] = strtof(buf, &pEnd);
			memcpy(buf, &pEnd[1], strlen(pEnd));
		}
				
		selectionSort(notas);
		
		float notaFinal = notas[1] + notas[2] + notas[3];
		printf ("%.1f\n", notaFinal);
		
	}
	
	return (0);
}
