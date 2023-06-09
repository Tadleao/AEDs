class No{
    Personagem elemento;
	No dir;
	No esq;
	int nivel;
	No(Personagem elemento) {
        this(elemento, null, null, 1);
    }
	public No(Personagem elemento, No esq, No dir, int nivel) {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
		this.nivel = nivel;
    }
	public static int getNivel(No no) {
		return (no == null) ? 0 : no.nivel;
	}
	public void setNivel() {
		this.nivel = 1 + Math.max(getNivel(esq), getNivel(dir));
	}
}