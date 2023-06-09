#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
typedef struct{
	 char *nome;
	 int altura;
	 double peso;
	 char *corDoCabelo;
	 char *corDaPele;
	 char *corDosOlhos;
	 char *anoNascimento;
	 char *genero;
	 char *homeworld;
	}Personagem;
typedef struct Celula{
    Personagem *elemento;
    struct Celula *prox;
}Celula;
typedef struct FilaF{
    struct Celula *primeiro, *ultimo;
    int size;
} FilaF;
// ---------------Conversão de tipo--------------- //
	double power(double x, int y)
	{
		double a = 1.0;
		if(y>0)
		{
		for(int i = 0; i<y;i++)
		{a = a*x;}
		}
		else{if(y<0){for(int i = y; i<0;i++)
		{a = a/x;}}}
	return(a);
	}
int convert(char *s)
{
   double resp = 0;
   for(int i = 0;i<strlen(s);i++)
   {
	resp += ((int)(s[i])-48) * power(10, strlen(s)-1-i);
   }
   return((int)resp);
}
double convertd(char *s)
{
int y = 0;
   double resp = 0.0;
   int dec = 0;
   while(s[y] != '.' && y<strlen(s))
   {
	   y++;
   }
   y--;
   for(int i = 0;i<strlen(s);i++)
   {	
		if(s[i] != '.' && s[i] != ',')
		{
		resp += ((int)(s[i])-48) * power(10, y-i);
		}
		else{y++;}
   }
	for(int i =0;i<strlen(s);i++)
	{if(s[i] == ','){dec++;}}
	if(dec>0){resp/=10;}
   return(resp);
}
// ---------------Métodos Personagem--------------- //
void imprimir(Personagem* x)
{
	printf(" ## %s ## %d ## %g ## %s ## %s ## %s ## %s ## %s ## %s ## \n", x->nome,x->altura,x->peso,x->corDoCabelo,x->corDaPele,x->corDosOlhos,x->anoNascimento,x->genero,x->homeworld);
}
Personagem* init()
{
	Personagem *tmp = malloc(sizeof(Personagem));
	tmp->nome = malloc(sizeof(char*));
	tmp->peso = 0.0;
	tmp->altura = 0;
	tmp->corDoCabelo = malloc(sizeof(char*));
	tmp->corDaPele = malloc(sizeof(char*));
	tmp->corDosOlhos = malloc(sizeof(char*));
	tmp->anoNascimento = malloc(sizeof(char*));
	tmp->genero = malloc(sizeof(char*));
	tmp->homeworld = malloc(sizeof(char*));
	return (tmp);
}
Personagem* ler(char *s)
{
	int y = 0;
	int i = 0;
	Personagem *tmp = malloc(sizeof(Personagem));
	int cont = 0; 
	bool resp = true;
	char *data;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->nome = data;  
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			if(strcmp(data, "unknown") == 0){tmp->altura = 0;}
			else{tmp->altura = convert(data);}
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		double x = 0.0;
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			if(strcmp(data, "unknown") == 0){tmp->peso = 0.0;}
			else{tmp->peso = convertd(data);}
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->corDoCabelo = data;  
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->corDaPele = data;  
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->corDosOlhos = data;  
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->anoNascimento = data;  
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->genero = data;  
			resp = false;
		}
	}
	resp = true;
	cont = 0;
	while(resp)
	{
	    i++;data = malloc(sizeof(char*));
		if(s[i] == ':')
		{
			y = i+3;
			while(s[y] != '\'')
			{
			
			data[cont] = s[y];data[cont+1] = '\0';
			y++;
			cont++;
			}
			data[cont] = '\0';
			i = y+1;
			tmp->homeworld = data;  
			resp = false;
		}
	}
	data = NULL;
	free(data);
	return(tmp);
}
//-----------------Metodos FilaF-----------------//
Celula* new_celula(){
    Celula *temp = (Celula*)malloc(sizeof(Celula));
    temp->elemento = malloc(sizeof(Personagem));
    return temp;
}
FilaF* new_fila(){
    FilaF* temp = malloc(sizeof(FilaF));
    temp->primeiro = new_celula();
	temp->ultimo = temp->primeiro;
    temp->size = 0;
    return temp;
}
Personagem* remover_F(FilaF* x)
{
	Personagem* resp = x->primeiro->elemento;
	Celula* tmp = x->primeiro;
	x->primeiro = x->primeiro->prox;
	x->size--;
	tmp->elemento = NULL;
	tmp->prox = NULL;
	tmp = NULL;
	free(tmp);
	x->ultimo->prox = x->primeiro;
	return(resp);
}
void inserir_F(FilaF* x, Personagem* y) {

   //validar insercao
   if (x->size == 5) {
      remover_F(x);
   }
   x->ultimo->elemento = y;
   x->ultimo->prox = new_celula();
   x->ultimo = x->ultimo->prox;
   x->ultimo->prox=x->primeiro;
   x->size++;
}
void imprimirF(FilaF* x)
{
	double media = 0;
	for(Celula* i = x->primeiro; i != x->ultimo; i = i->prox)
	{
		media += i->elemento->altura;
	}
	media = round(media/x->size);
	printf("%g\n", media);
}
int main()
{
	setlocale(LC_ALL, "pt_BR_utf8");
	int op = 0;
	int pos = 0;
	char s[100];// = malloc(sizeof(char*));
	scanf("%s", s);
	getchar();
	int qtde = 0;
	FILE *ps;
	char *sd = malloc(sizeof(char*));
	Personagem *x = init();
	FilaF *y = new_fila();
	while(!(strlen(s) == 3 && s[0]== 'F' && s[1]=='I' && s[2]=='M'))
	{
	ps = fopen(s,"r");
	fgets(sd, 1000, ps);
	x = ler(sd);
	inserir_F(y, x);
	imprimirF(y);
	scanf("%s", s);
	getchar();
	} 
	scanf("%d",&op);
	getchar();
	for(int i = 0;i<op;i++)
	{
		scanf("%s",s);
		getchar();
		if(strcmp(s,"I") == 0)
		{
			Personagem *tmp = init();
			scanf("%s",s);
			getchar();
			ps = fopen(s,"r");
			fgets(sd, 1000, ps);
			tmp = ler(sd);
			inserir_F(y, tmp);
			imprimirF(y);
			tmp = NULL;
			free(tmp);
		}
		else
		{
			if(strcmp(s,"R") ==0)
			{
				Personagem* tmp = remover_F(y);
				printf("(R) %s\n", tmp->nome);
			}
		}
	}
	x = NULL;
	free(x);
	fclose(ps);
}