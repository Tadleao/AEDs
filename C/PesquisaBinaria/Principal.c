#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
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
typedef struct{
	Personagem *y;
	int n;
	int cmp;
}Lista;
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
Lista* init2()
{
	Lista *tmp = malloc(sizeof(Lista));
	tmp->y = malloc(100 * sizeof(Personagem));
	tmp->n = 0;
	tmp->cmp = 0;
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
// ---------------Métodos Lista--------------- /
void inserirInicio(Personagem* y, Lista* x)
	{
		if(x->n<100)
		{
		  for(int i=x->n;i>0;i--)
		  {
			  x->y[i] = x->y[i-1];
		  }			
			x->y[0] = *y;
			x->n++;
		}
		else
		{printf("Erro");}
	}
	void inserirFim(Personagem* y, Lista* x)
	{
		if(x->n < 100)
		{
		  x->y[x->n] = *y;
		  x->n++;		  
		}
		else
		{printf("Erro");}
    }
	void inserir(Lista* x, Personagem* y, int pos)
	{
		if(x->n<100 && pos>=0 && pos<100)
		{
			for(int i = x->n;i>pos;i--)
			{
				x->y[i] = x->y[i-1];
			}
			x->y[pos] = *y;
			x->n++;
		}
		else
		{printf("Erro");}
	}
	Personagem removerInicio (Lista* x) 
	{
		if (x->n != 0) 
		{
        
			Personagem resp = x->y[0];
			x->n--;
			for(int i = 0;i<x->n;i++)
			{
				x->y[i] = x->y[i+1];
			}
			return(resp);
		}
		else{printf("Erro");}
	}
	Personagem removerFim(Lista* x)
	{
		if (x->n != 0) 
		{
		Personagem resp = x->y[(x->n)-1];
		x->n--;
		return (resp);
		}
		else{printf("Erro");}
	}
	Personagem remover(int pos, Lista* x)
	{
		if (x->n != 0 && pos>=0 && pos<x->n) 
		{
			Personagem resp = x->y[pos];
			x->n--;
			for(int i = pos;i<x->n;i++)
			{
				x->y[i] = x->y[i+1];
			}
			return(resp);
		}
		else{printf("Erro");}
	}
void imprimir2(Lista* x)
{
	for(int i = 0;i<x->n;i++)
	{
	printf("[%d]  ## %s ## %d ## %g ## %s ## %s ## %s ## %s ## %s ## %s ## \n",i, x->y[i].nome,x->y[i].altura,x->y[i].peso,x->y[i].corDoCabelo,x->y[i].corDaPele,x->y[i].corDosOlhos,x->y[i].anoNascimento,x->y[i].genero,x->y[i].homeworld);
	}
}
void ordenar(Lista* x)
{
	for (int i = 1; i < x->n; i++) {
      Personagem tmp = x->y[i];
      int j = i - 1;
      while ((j >= 0) && (strcmp(tmp.nome,x->y[j].nome)>0)) {
         x->y[j + 1] = x->y[j];
         j--;
      }
      x->y[j+1] = tmp;
   }
}
bool pesquisar(Lista* x, char *s, int high, int low)
{
	bool resp = false;
	while((!resp) && high>=low)
	{
	int i = (high + low)/2;
	if(strcmp(s,x->y[i].nome) == 0)
	{
		resp = true;
		x->cmp++;
	}
	else{
		if(strcmp(s,x->y[i].nome)>0)
		{
			low = i+1;
			x->cmp++;
		}
		else{
			if(strcmp(s,x->y[i].nome)<0)
			{
				high = i-1;
				x->cmp++;
			}
		}
		}
	}
	return(resp);
}
int main()
{
	setlocale(LC_ALL, "pt_BR_utf8");
	clock_t t;
	int mat = 705178;
	int op = 0;
	int pos = 0;
	FILE *log = fopen("705178_binaria.txt","w");
	char s[100];// = malloc(sizeof(char*));
	scanf("%s", s);
	getchar();
	FILE *ps;
	char *sd = malloc(sizeof(char*));
	Personagem *x = init();
	Lista *y = init2();
	while(!(strlen(s) == 3 && s[0]== 'F' && s[1]=='I' && s[2]=='M'))
	{
	ps = fopen(s,"r");
	fgets(sd, 1000, ps);
	x = ler(sd);
	inserirFim(x,y);
	scanf("%s", s);
	getchar();
	} 
	scanf("%[^\n]", s);
	getchar();
	//ordenar(y);
	t=clock();
	while(!(strlen(s) == 3 && s[0]== 'F' && s[1]=='I' && s[2]=='M'))
	{
		if(pesquisar(y,s, y->n, 0))
		{
			printf("SIM\n");
		}
		else{printf("NAO\n");}
		scanf("%[^\n]", s);
		getchar();
	}
	t=clock()-t;
	fprintf(log, "M:%d\t",mat);
	fprintf(log, "T:%d\t",t);
	fprintf(log, "Cmp:%d\t",y->cmp);
	x = NULL;
	free(x);
	y=NULL;
	free(y);
	fclose(ps);
	fclose(log);
}