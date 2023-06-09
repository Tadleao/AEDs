import java.io.*;
import java.util.*;
class PrincipalAB{
	public static void main(String[] args) throws Exception
	{
		try{
		int mat = 705178;
		FileWriter log = new FileWriter("705178_arvoreBinaria.txt");
		String s = MyIO.readLine().replaceAll("é","\u00e9");
		Arvore y = new Arvore();
		while(!(s.length() == 3 && s.charAt(0)== 'F' && s.charAt(1)=='I' && s.charAt(2)=='M'))
	    {
			Personagem tmp = new Personagem();
			tmp.ler(s);
			y.inserir(tmp);
			s = MyIO.readLine().replaceAll("é","\u00e9");
		}
		s = MyIO.readLine().replaceAll("é","\u00e9");
		long start = System.currentTimeMillis();
		while(!(s.length() == 3 && s.charAt(0)== 'F' && s.charAt(1)=='I' && s.charAt(2)=='M'))
		{
			System.out.print(s + " raiz ");
			if(y.pesquisar(s))
			{System.out.println("SIM");}
			else
			{System.out.println("NÃO");}
		s = MyIO.readLine().replaceAll("é","\u00e9");
		}
		long elapsed = System.currentTimeMillis() - start;
		log.write("M:"+mat + "\tT:" + elapsed + "\tCMP:" + y.cmp);
		log.close();
		}
		catch(IOException e)
		{
			System.out.println("Erro");
		}
	}
}