class Arvore{
	No raiz;
	int cmp;
	Arvore() {
		raiz = null;
		cmp = 0;
	}
	void inserir(Personagem x)
	{
		raiz = inserir(x, raiz);
	}
	No inserir(Personagem x, No i)
	{
		if(i == null)
		{i = new No(x);}
		else if( x.getNome().compareTo(i.elemento.getNome()) < 0)
		{i.esq = inserir(x, i.esq);}
		else
		{i.dir = inserir(x,i.dir);}
		return i;
	}
	boolean pesquisar(String nome)
	{   
		boolean resp = pesquisar(nome, raiz);
		return resp;
	}
	boolean pesquisar(String nome, No i)
	{
		boolean resp = false;
		if(i == null){ resp = false;}
		else if(i.elemento.getNome().compareTo(nome) == 0)
		{
			resp = true;
			cmp++;
		}
		else if(i.elemento.getNome().compareTo(nome) > 0)
		{
			System.out.print("esq ");
			resp = pesquisar(nome, i.esq);
			cmp++;
		}
		else if(i.elemento.getNome().compareTo(nome) < 0)
		{
			System.out.print("dir ");
			resp = pesquisar(nome, i.dir);
			cmp++;
		}
		return resp;
	}
}
