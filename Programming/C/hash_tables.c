#include <stdio.h>

struct nlist{
	struct nlist *next;
	char *def_name;
	char *rep_text;
};

#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE];

unsigned hash(char *s){
	unsigned hashval;

	for(hashval=0;*s!='\0';s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s){
	struct nlist *np;

	for(np=hashtable[hash(s)];np!=NULL;np=np->next)
		if(strcmp(s, np->def_name)==0)
			return np;
	return NULL;
}

struct nlist *lookup(char *);
char *strdup(char *);

struct nlist *install(char *def_name, char *rep_text){
	struct nlist *np;
	unsigned hashval;

	if((np=lookup(def_name))==NULL){
		np = (struct nlist *)malloc(sizeof(*np));
		if(np == NULL || (np->def_name = strdup(def_name)) == NULL)
			return NULL;
		hashval = hash(def_name);
		np->next = hashtable[hashval];
		hashtable[hashval] = np;
	}else free((void *)np->rep_text);
	if((np->rep_text = strup(rep_text)) == NULL)
		return NULL;
	return np;
}

int main(){

}