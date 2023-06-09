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
typedef struct{
    Celula *topo;
	int size;
}PilhaF;
Celula* new_celula(){
    Celula *temp = (Celula*)malloc(sizeof(Celula));
    temp->elemento = malloc(sizeof(Personagem));
    return temp;
}
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
//-----------------Metodos PilhaF-----------------//
PilhaF* init_P()
{
	PilhaF *tmp = malloc(sizeof(PilhaF));
	tmp->topo = new_celula();
	tmp->size = 0;
}
void inserir_P(PilhaF *x, Personagem *y)
{
	Celula *tmp = new_celula();
	tmp->elemento = y;
	tmp->prox = x->topo;
	x->topo = tmp;
	tmp = NULL;
	x->size++;
	free(tmp);
}
Personagem* remover_P(PilhaF *x)
{
	Personagem* resp = x->topo->elemento;
	Celula *tmp = x->topo;
	x->topo = x->topo->prox;
	free(tmp);
	x->size--;
	return(resp);
}
void mostrar_P(Celula *i, int qtde)
{
	if(i->prox!=NULL)
	{
		mostrar_P(i->prox,--qtde);
		printf("[%d] ",qtde);
		imprimir(i->elemento);
	}
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
	PilhaF *y = init_P();
	while(!(strlen(s) == 3 && s[0]== 'F' && s[1]=='I' && s[2]=='M'))
	{
	ps = fopen(s,"r");
	fgets(sd, 1000, ps);
	x = ler(sd);
	inserir_P(y, x);
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
			inserir_P(y, tmp);
			tmp = NULL;
			free(tmp);
		}
		else
		{
			if(strcmp(s,"R") ==0)
			{
				Personagem* tmp = remover_P(y);
				printf("(R) %s\n", tmp->nome);
			}
		}
	}
	mostrar_P(y->topo, y->size);
	x = NULL;
	free(x);
	fclose(ps);
}