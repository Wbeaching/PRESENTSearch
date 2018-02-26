#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Types.h"
#include "DesFunc.h"
#include "LookUpTables.h"
#include "DiffDistribution.h"
#include "Search.h"
#include "GlobalV.h"
#include "Tables.h"
u64 genRandom64(){
	u64 x;
	srand((unsigned long)time(NULL));
	for(int i=0;i<5;i++){
		x=x<<15|rand();
	}
	return x;
}

void print64(u64 x){
	printf("%llx\n",x);
}
void print4t16(u8* x){
	for(int i=0;i<16;i++){
		printf("%x\t",*(x+i));
	}
	printf("\n");
}

void printUnP(){
	for(int i=0;i<64;i++){
		for(int j=0;j<64;j++){
			if(PTable[j]==i){
				printf("%d,",j);
				break;
			}
		}
	}
}

int main(){
	genDiffTable();
	genPTableLookUp();

	//printDiffTable();
	printPTableLookUp(7);
	u64 x;
	u8 sb[16];
	bool bit[64];
	x=genRandom64();
	print64(x);
	word642word8(sb,x);
	word82word64(&x,sb);
	print64(x);
	print64(x);
	word642bit(bit,x);
	bit2word64(&x,bit);
	print64(x);
	x=permutation(x);
	print64(x);
	x=unPermutation(x);
	print64(x);
	x=permutationTL(x);
	print64(x);
	system("pause");
}