#include <stdio.h>
#include <assert.h>

int main (void) {
	int nota;
	printf("Digitar a nota do Aluno: ");
	scanf("%d", &nota);

#ifndef NDEBUG
	//Verificar se a nota está entre 0 e 10 //
	printf("%s: %s: %d\n", __FILE__, __FUNCTION__, nota);
#endif
	assert(nota >= 0 && nota <= 10);

	if(nota <7){
		printf("Aluno Reprovado\n");
	} else {
		printf("Aluno aprovado\n");
	}

}
