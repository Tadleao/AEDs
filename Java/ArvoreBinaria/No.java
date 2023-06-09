class No{
    Personagem elemento;
	No dir;
	No esq;
	No(Personagem elemento) {
        this(elemento, null, null);
    }
	public No(Personagem elemento, No esq, No dir) {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
    }
}