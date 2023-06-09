class NoAN {
  public boolean cor;
  public Personagem elemento;
  public NoAN esq, dir;

  public NoAN() {
    this(null);
  }

  public NoAN(Personagem elemento) {
    this(elemento, false, null, null);
  }

  public NoAN(Personagem elemento, boolean cor) {
    this(elemento, cor, null, null);
  }

  public NoAN(Personagem elemento, boolean cor, NoAN esq, NoAN dir) {
    this.cor = cor;
    this.elemento = elemento;
    this.esq = esq;
    this.dir = dir;
  }
}