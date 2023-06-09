class PilhaF{
	Celula topo;
	PilhaF(){topo = null;}
	void empilhar(Personagem x)
	{
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = tmp;
		tmp = null;
	}
	Personagem desempilhar()
	{
      Personagem resp = topo.elemento; 
      topo = topo.prox; 
		return resp;
	}
	int tamanho()
	{
		int resp = 0;
		for(Celula i = topo;i != null; i = i.prox, resp++);
		return(resp);
	}
	public void mostrar() {
		int qtde =0;
		for (Celula i = topo; i != null; i = i.prox) {
			System.out.print("[" + qtde++ + "] ");
			i.elemento.imprimir();
		}
	}
	public void mostrarRec(Celula i, int qtde)
	{
		if(i != null)
		{
			mostrarRec(i.prox, --qtde);
			System.out.print("[" + qtde + "] ");
			i.elemento.imprimir();
		}
	}
}
