class PrincipalLista{
	public static void main(String[] args) throws Exception
	{
		int x = 0;
		String s = MyIO.readLine().replaceAll("é","\u00e9");
		ListaF y = new ListaF();
		while(!(s.length() == 3 && s.charAt(0)== 'F' && s.charAt(1)=='I' && s.charAt(2)=='M'))
	    {
			Personagem tmp = new Personagem();
			tmp.ler(s);
			y.inserirFim(tmp);
			s = MyIO.readLine().replaceAll("é","\u00e9");
		}
		x = MyIO.readInt();
		for(int i = 0;i<x;i++)
		{
			s = MyIO.readString().replaceAll("é","\u00e9");
			if(s.equals("II"))
			{
				Personagem tmp = new Personagem();
				tmp.ler(MyIO.readString().replaceAll("é","\u00e9"));
				y.inserirInicio(tmp);
				tmp = null;
			}
			else if(s.equals("IF"))
			{
				Personagem tmp = new Personagem();
				tmp.ler(MyIO.readString().replaceAll("é","\u00e9"));
				y.inserirFim(tmp);
				tmp = null;
			}
			else if(s.equals("I*"))
			{
				Personagem tmp = new Personagem();
				int pos = MyIO.readInt();
				tmp.ler(MyIO.readString().replaceAll("é","\u00e9"));
				y.inserir(tmp, pos);
				tmp = null;
			}
			else if(s.equals("RI"))
			{
				System.out.println("(R) " + y.removerInicio().getNome());
			}
			else if(s.equals("RF"))
			{
				System.out.println("(R) " + y.removerFim().getNome());
			}
			else if(s.equals("R*"))
			{
				System.out.println("(R) " + y.remover(MyIO.readInt()).getNome());
			}
		}
		y.mostrar();
	}
}
