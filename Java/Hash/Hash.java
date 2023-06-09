class Hash{
	Personagem tabela[];
	int tam;
	int res;
	int tot;
	int resUs;
	int cmp;
	Hash(){
		this(21,9);
	}
	Hash(int tam, int res)
	{
		this.tam=tam;
		this.res=res;
		this.tot=tam+res;
		this.tabela=new Personagem[tam+res];
		cmp =0;
		for(int i =0;i<tot;i++)
		{
			tabela[i]=null;
		}
		resUs=0;
	}
	int transf(Personagem x)
	{return (x.getAltura()%tam);}
	
	public boolean inserir(Personagem elemento) {
      boolean resp = false;
      if (elemento != null) {
         int pos = transf(elemento);
         if (tabela[pos] == null) {
            tabela[pos] = elemento;
            resp = true;
         } else if (resUs < res) {
            tabela[tam + resUs] = elemento;
            resUs++;
            resp = true;
         }
      }
      return resp;
   }

   public boolean pesquisar(String elemento) {
      boolean resp = false;
	  Personagem tmp = new Personagem();
	  tmp.ler2(elemento.replaceAll(" ","").replaceAll("�","\u00e9"));
      int pos = transf(tmp);
      if (tabela[pos]!=null && tabela[pos].getNome().compareTo(elemento)==0) {
		  cmp++;
         resp = true;
      } else if (tabela[pos] != null) {
         for (int i = 0; i < resUs; i++) {
			 cmp++;
            if (tabela[tam + i].getNome().compareTo(elemento)==0) {
               resp = true;
               i = resUs;
            }
         }
      }
      return resp;
   }

}