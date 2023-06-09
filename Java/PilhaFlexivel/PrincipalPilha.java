class PrincipalPilha{
	public static void main(String[] args) throws Exception
	{
		int x = 0;
		String s = MyIO.readLine().replaceAll("é","\u00e9");
		PilhaF y = new PilhaF();
		while(!(s.length() == 3 && s.charAt(0)== 'F' && s.charAt(1)=='I' && s.charAt(2)=='M'))
	    {
			Personagem tmp = new Personagem();
			tmp.ler(s);
			y.empilhar(tmp);
			s = MyIO.readLine().replaceAll("é","\u00e9");
		}
		x = MyIO.readInt();
		for(int i = 0;i<x;i++)
		{
			s = MyIO.readString().replaceAll("é","\u00e9");
			if(s.equals("I"))
			{
				Personagem tmp = new Personagem();
				tmp.ler(MyIO.readString().replaceAll("é","\u00e9"));
				y.empilhar(tmp);
			}
			else if(s.equals("R"))
			{
				System.out.println("(R) " + y.desempilhar().getNome());
			}
		}
		y.mostrarRec(y.topo,y.tamanho());
	}
}