#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *);
void decrypt(char *);
static int algo;

int main(){
	srand(time(0));
	algo = rand()%20;
	char name[20];
	printf("Enter something to encrypt: ");
	scanf("%[^\n]", name);
	printf("Length of name: %d\n", strlen(name));
	printf("name: %s\n", name);

	encrypt(name);
	printf("\nAfter Encryption:-\n");
	printf("name: %s\n", name);

	decrypt(name);
	printf("\nAfter Decryption:-\n");
	printf("name: %s\n", name);
}

void encrypt(char input[]){
	int in_len = strlen(input);

	for(int i=0;i<in_len;i++){
		input[i] = input[i] + algo;
	}
}

void decrypt(char input[]){
	int in_len = strlen(input);

	for(int i=0;i<in_len;i++){
		input[i] = input[i]-algo;
	}
}