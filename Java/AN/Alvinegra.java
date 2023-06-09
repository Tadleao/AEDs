class Alvinegra {
    NoAN raiz; // Raiz da arvore.
   int cmp;
   /**
    * Construtor da classe.
    */
   public Alvinegra() {
      raiz = null;
	  cmp=0;
   }

   /**
    * Metodo publico iterativo para pesquisar elemento.
    * 
    * @param elemento Elemento que sera procurado.
    * @return <code>true</code> se o elemento existir,
    *         <code>false</code> em caso contrario.
    */
   public boolean pesquisar(String elemento) {
      return pesquisar(elemento, raiz);
   }

   /**
    * Metodo privado recursivo para pesquisar elemento.
    * 
    * @param elemento Elemento que sera procurado.
    * @param i        NoAN em analise.
    * @return <code>true</code> se o elemento existir,
    *         <code>false</code> em caso contrario.
    */
   private boolean pesquisar(String elemento, NoAN i) {
      boolean resp;
      if (i == null) {
		  cmp++;
         resp = false;
      } else if (elemento.compareTo( i.elemento.getNome())==0) {
		  cmp++;
         resp = true;
      } else if (elemento.compareTo(i.elemento.getNome())<0) {
		  cmp++;
		  System.out.print("esq ");
         resp = pesquisar(elemento, i.esq);
      } else {
		  cmp++;
		  System.out.print("dir ");
         resp = pesquisar(elemento, i.dir);
      }
      return resp;
   }
	public void caminhar(NoAN i){
		if(i!=null){
		caminhar(i.esq);
		System.out.println(i.elemento.getNome());
		caminhar(i.dir);}
	}
   public void inserir(Personagem elemento) throws Exception {
      // Se a arvore estiver vazia
      if (raiz == null) {
         raiz = new NoAN(elemento);
        // System.out.println("Antes, zero elementos. Agora, raiz(" + raiz.elemento + ").");

      // Senao, se a arvore tiver um elemento
      } else if (raiz.esq == null && raiz.dir == null) {
         if (elemento.getNome().compareTo(raiz.elemento.getNome())<0) {
            raiz.esq = new NoAN(elemento);
          //  System.out.println("Antes, um elemento. Agora, raiz(" + raiz.elemento + ") e esq(" + raiz.esq.elemento + ").");
         } else {
            raiz.dir = new NoAN(elemento);
            //System.out.println("Antes, um elemento. Agora, raiz(" + raiz.elemento + ") e dir(" + raiz.dir.elemento + ").");
         }

      // Senao, se a arvore tiver dois elementos (raiz e dir)
      } else if (raiz.esq == null) {
         if (elemento.getNome().compareTo(raiz.elemento.getNome())<0) {
            raiz.esq = new NoAN(elemento);
            //System.out.println("Antes, dois elementos(A). Agora, raiz(" + raiz.elemento + "), esq (" + raiz.esq.elemento + ") e dir(" + raiz.dir.elemento + ").");

         } else if (elemento.getNome().compareTo(raiz.dir.elemento.getNome())<0) {
            raiz.esq = new NoAN(raiz.elemento);
            raiz.elemento = elemento;
           // System.out.println("Antes, dois elementos(B). Agora, raiz(" + raiz.elemento + "), esq (" + raiz.esq.elemento + ") e dir(" + raiz.dir.elemento + ").");
         } else {
            raiz.esq = new NoAN(raiz.elemento);
            raiz.elemento = raiz.dir.elemento;
            raiz.dir.elemento = elemento;
           // System.out.println("Antes, dois elementos(C). Agora, raiz(" + raiz.elemento + "), esq (" + raiz.esq.elemento + ") e dir(" + raiz.dir.elemento + ").");
         }
         raiz.esq.cor = raiz.dir.cor = false;

      // Senao, se a arvore tiver dois elementos (raiz e esq)
      } else if (raiz.dir == null) {
         if (elemento.getNome().compareTo(raiz.elemento.getNome())>0) {
            raiz.dir = new NoAN(elemento);
           // System.out.println("Antes, dois elementos(D). Agora, raiz(" + raiz.elemento + "), esq (" + raiz.esq.elemento + ") e dir(" + raiz.dir.elemento + ").");

         } else if (elemento.getNome().compareTo(raiz.esq.elemento.getNome())>0) {
            raiz.dir = new NoAN(raiz.elemento);
            raiz.elemento = elemento;
            System.out.println("Antes, dois elementos(E). Agora, raiz(" + raiz.elemento + "), esq (" + raiz.esq.elemento + ") e dir(" + raiz.dir.elemento + ").");

         } else {
            raiz.dir = new NoAN(raiz.elemento);
            raiz.elemento = raiz.esq.elemento;
            raiz.esq.elemento = elemento;
            //System.out.println("Antes, dois elementos(F). Agora, raiz(" + raiz.elemento + "), esq (" + raiz.esq.elemento + ") e dir(" + raiz.dir.elemento + ").");
         }
         raiz.esq.cor = raiz.dir.cor = false;

      // Senao, a arvore tem tres ou mais elementos
      } else {
        // System.out.println("Arvore com tres ou mais elementos...");
         inserir(elemento, null, null, null, raiz);
      }
      raiz.cor = false;
   }

   private void balancear(NoAN bisavo, NoAN avo, NoAN pai, NoAN i) {
      // Se o pai tambem e preto, reequilibrar a arvore, rotacionando o avo
      if (pai.cor == true) {
         // 4 tipos de reequilibrios e acoplamento
         if (pai.elemento.getNome().compareTo(avo.elemento.getNome())>0) { // rotacao a esquerda ou direita-esquerda
            if (i.elemento.getNome().compareTo(pai.elemento.getNome())>0) {
               avo = rotacaoEsq(avo);
            } else {
               avo = rotacaoDirEsq(avo);
            }
         } else { // rotacao a direita ou esquerda-direita
            if (i.elemento.getNome().compareTo(pai.elemento.getNome())<0) {
               avo = rotacaoDir(avo);
            } else {
               avo = rotacaoEsqDir(avo);
            }
         }
         if (bisavo == null) {
            raiz = avo;
         } else if (avo.elemento.getNome().compareTo( bisavo.elemento.getNome())<0) {
            bisavo.esq = avo;
         } else {
            bisavo.dir = avo;
         }
         // reestabelecer as cores apos a rotacao
         avo.cor = false;
         avo.esq.cor = avo.dir.cor = true;
        // System.out.println("Reestabeler cores: avo(" + avo.elemento + "->branco) e avo.esq / avo.dir("
        //       + avo.esq.elemento + "," + avo.dir.elemento + "-> pretos)");
      } // if(pai.cor == true)
   }

   /**
    * Metodo privado recursivo para inserir elemento.
    * 
    * @param elemento Elemento a ser inserido.
    * @param avo      NoAN em analise.
    * @param pai      NoAN em analise.
    * @param i        NoAN em analise.
    * @throws Exception Se o elemento existir.
    */
   private void inserir(Personagem elemento, NoAN bisavo, NoAN avo, NoAN pai, NoAN i) throws Exception {
      if (i == null) {
         if (elemento.getNome().compareTo(pai.elemento.getNome())<0) {
            i = pai.esq = new NoAN(elemento, true);
         } else {
            i = pai.dir = new NoAN(elemento, true);
         }
         if (pai.cor == true) {
            balancear(bisavo, avo, pai, i);
         }
      } else {
         // Achou um 4-no: eh preciso fragmeta-lo e reequilibrar a arvore
         if (i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true) {
            i.cor = true;
            i.esq.cor = i.dir.cor = false;
            if (i == raiz) {
               i.cor = false;
            } else if (pai.cor == true) {
               balancear(bisavo, avo, pai, i);
            }
         }
         if (elemento.getNome().compareTo(i.elemento.getNome())<0) {
            inserir(elemento, avo, pai, i, i.esq);
         } else if (elemento.getNome().compareTo(i.elemento.getNome())>0) {
            inserir(elemento, avo, pai, i, i.dir);
         } else {
            throw new Exception("Erro inserir (elemento repetido)!");
         }
      }
   }

   private NoAN rotacaoDir(NoAN no) {
      //System.out.println("Rotacao DIR(" + no.elemento + ")");
      NoAN noEsq = no.esq;
      NoAN noEsqDir = noEsq.dir;

      noEsq.dir = no;
      no.esq = noEsqDir;

      return noEsq;
   }

   private NoAN rotacaoEsq(NoAN no) {
     // System.out.println("Rotacao ESQ(" + no.elemento + ")");
      NoAN noDir = no.dir;
      NoAN noDirEsq = noDir.esq;

      noDir.esq = no;
      no.dir = noDirEsq;
      return noDir;
   }

   private NoAN rotacaoDirEsq(NoAN no) {
      no.dir = rotacaoDir(no.dir);
      return rotacaoEsq(no);
   }

   private NoAN rotacaoEsqDir(NoAN no) {
      no.esq = rotacaoEsq(no.esq);
      return rotacaoDir(no);
   }
}
