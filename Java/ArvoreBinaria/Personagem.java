import java.io.*;
import java.util.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
class Personagem{
	private int altura;
	private String nome;
	private double peso;
	private String corDoCabelo;
	private String corDaPele;
	private String corDosOlhos;
	private String anoNascimento;
	private String genero;
	private String homeworld;
	public Personagem()
	{
	  altura = 0;
	  nome = "";
	  peso = 0.0;
	  corDoCabelo = "";
	  corDaPele = "";
	  corDosOlhos = "";
	  anoNascimento = "";
	  genero = "";
	  homeworld = "";
	}
	public Personagem( int altura, String nome, double peso, String corDoCabelo, String corDaPele, String corDosOlhos, String anoNascimento, String genero, String homeworld)
	{
	 this.altura = altura;
	 this.nome = nome;
	 this.peso = peso;
	 this.corDoCabelo = corDoCabelo;
	 this.corDaPele = corDaPele;
	 this.corDosOlhos = corDosOlhos;
	 this.anoNascimento = anoNascimento;
	 this.genero = genero;
	 this.homeworld = homeworld;
	}
	int getAltura(){return (altura);}
	String getNome(){return (nome);}
	double getPeso(){return peso;}
	String getCorDoCabelo(){return corDoCabelo;}
	String getCorDaPele(){return corDaPele;}
	String getCorDosOlhos(){return corDosOlhos;}
	String getAnoNascimento(){return anoNascimento;}
	String getGenero(){return genero;}
	String getHomeworld(){return homeworld;}
	void setAltura(int x){this.altura = x;}
	void setNome(String x){this.nome = x ;}
	void setPeso(double x){this.peso = x;}
	void setCorDoCabelo(String x){this.corDoCabelo = x;}
	void setCorDaPele(String x){this.corDaPele = x;}
	void setCorDosOlhos(String x){this.corDosOlhos = x;}
	void setAnoNascimento(String x){this.anoNascimento = x;}
	void setGenero(String x){this.genero = x;}
	void setHomeworld(String x){this.homeworld = x;}
	void ler(String s)
	{
		String[] data = new String[100];
		try{
		String p;
		String aux;
		int cont = 0;
		FileReader fl = new FileReader(s);
		BufferedReader b = new BufferedReader(fl);
		p = b.readLine();
		for(int i = 0;i<p.length();i++)
		{
			if(p.charAt(i) == '\'')
			{
				int y = i+1;
				data[cont] = "";
				while(p.charAt(y)!= '\'')
				{
					data[cont] += p.charAt(y);
					y++;
				}
				cont++;
				i = y+1;
			}
		}
		}  catch (IOException e) {
        System.err.printf("Erro na abertura do arquivo: %s.\n",
          e.getMessage());
		}
		this.setNome(data[1]);
		try{this.setAltura(Integer.parseInt(data[3]));}catch(NumberFormatException e){}
		try{String b = data[5].replaceAll(",","");this.setPeso(Double.parseDouble(b));}catch(NumberFormatException e){}
		this.setCorDoCabelo(data[7]);
		this.setCorDaPele(data[9]);
		this.setCorDosOlhos(data[11]);
		this.setAnoNascimento(data[13]);
		this.setGenero(data[15]);
		this.setHomeworld(data[17]);
	}
	void ler2(String s)
	{
		String[] data = new String[100];
		try{
		String p;
		String aux;
		int cont = 0;
		FileReader fl = new FileReader("/tmp/personagens/"+s+".txt");
		BufferedReader b = new BufferedReader(fl);
		p = b.readLine();
		for(int i = 0;i<p.length();i++)
		{
			if(p.charAt(i) == '\'')
			{
				int y = i+1;
				data[cont] = "";
				while(p.charAt(y)!= '\'')
				{
					data[cont] += p.charAt(y);
					y++;
				}
				cont++;
				i = y+1;
			}
		}
		}  catch (IOException e) {
        System.err.printf("Erro na abertura do arquivo: %s.\n",
          e.getMessage());
		}
		this.setNome(data[1]);
		try{this.setAltura(Integer.parseInt(data[3]));}catch(NumberFormatException e){}
		try{String b = data[5].replaceAll(",","");this.setPeso(Double.parseDouble(b));}catch(NumberFormatException e){}
		this.setCorDoCabelo(data[7]);
		this.setCorDaPele(data[9]);
		this.setCorDosOlhos(data[11]);
		this.setAnoNascimento(data[13]);
		this.setGenero(data[15]);
		this.setHomeworld(data[17]);
	}
	void imprimir()
	{
		DecimalFormatSymbols otherSymbols = new DecimalFormatSymbols(Locale.US);
		DecimalFormat df = new DecimalFormat("#.##########", otherSymbols);
		System.out.println(" ## " + nome + " ## " + altura + " ## " + df.format(peso) + " ## " + corDoCabelo + " ## " + corDaPele + " ## " + corDosOlhos + " ## " + anoNascimento + " ## " + genero + " ## " + homeworld + " ## ");
	}
	Personagem clonar()
	{
		Personagem tmp = this;
		return(tmp);
	}
}
