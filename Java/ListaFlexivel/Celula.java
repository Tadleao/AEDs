class Celula{
	Personagem elemento;
	Celula prox;
	Celula()
	{
		elemento = null;
		prox = null;
	}
	Celula(Personagem x)
	{
		this.elemento = x;
		prox = null;
	}
}
