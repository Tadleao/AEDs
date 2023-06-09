class Arvore{
	No raiz;
	int cmp;
	Arvore() {
		raiz = null;
		cmp = 0;
	}
	void inserir(Personagem x)throws Exception
	{
		raiz = inserir(x, raiz);
	}
	No inserir(Personagem x, No i) throws Exception
	{
		if(i == null)
		{i = new No(x);}
		else if( x.getNome().compareTo(i.elemento.getNome()) < 0)
		{i.esq = inserir(x, i.esq);}
		else
		{i.dir = inserir(x,i.dir);}
		return balancear(i);
	}
	private No rotacionarDir(No no) {
		//System.out.println("Rotacionar DIR(" + no.elemento + ")");
		No noEsq = no.esq;
		No noEsqDir = noEsq.dir;

		noEsq.dir = no;
		no.esq = noEsqDir;
		no.setNivel(); // Atualizar o nivel do no
		noEsq.setNivel(); // Atualizar o nivel do noEsq

		return noEsq;
	}

	private No rotacionarEsq(No no) {
		//System.out.println("Rotacionar ESQ(" + no.elemento + ")");
		No noDir = no.dir;
		No noDirEsq = noDir.esq;

		noDir.esq = no;
		no.dir = noDirEsq;

		no.setNivel(); // Atualizar o nivel do no
		noDir.setNivel(); // Atualizar o nivel do noDir
		return noDir;
	}
	private No balancear(No no) throws Exception {
		if (no != null) {
			int fator = No.getNivel(no.dir) - No.getNivel(no.esq);
			// Se balanceada
			if (Math.abs(fator) <= 1) {
				no.setNivel();
			// Se desbalanceada para a direita
			} else if (fator == 2) {
				int fatorFilhoDir = No.getNivel(no.dir.dir) - No.getNivel(no.dir.esq);
				// Se o filho a direita tambem estiver desbalanceado
				if (fatorFilhoDir == -1) {
					no.dir = rotacionarDir(no.dir);
				}
				no = rotacionarEsq(no);
			// Se desbalanceada para a esquerda
			} else if (fator == -2) {
				int fatorFilhoEsq = No.getNivel(no.esq.dir) - No.getNivel(no.esq.esq);
				// Se o filho a esquerda tambem estiver desbalanceado
				if (fatorFilhoEsq == 1) {
					no.esq = rotacionarEsq(no.esq);
				}
				no = rotacionarDir(no);
			} else {
				throw new Exception(
						"Erro no No(" + no.elemento + ") com fator de balanceamento (" + fator + ") invalido!");
			}
		}
		return no;
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