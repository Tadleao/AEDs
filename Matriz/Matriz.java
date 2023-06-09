class Matriz{
	No inicio;
	int ln;
	int cl;
	int qtd;
	Matriz()
	{
		this(3,3);
	}
	Matriz(int ln, int cl)
	{
		this.ln=ln;
		this.cl=cl;
		inicio = new No();
		qtd++;
		No a,b,c;
		a=inicio;b=inicio;c=null;
		for(int i=0;i<ln;i++)
		{
			for(int j =0;j<cl-1;j++)
			{
				b.dir = new No(qtd,null,b,null,c);
				qtd++;
				b=b.dir;
				if(c!=null)
				{
					c=c.dir;
				}
			}
			a.inf=new No(qtd,null,null,null,a);
			qtd++;
			c=a;a=a.inf;
			b=a;	
		}
		a.sup.inf=null;
		a.sup=null;
		a=null;
		qtd--;
	}
	void mostrar()
	{
		No a,b;
		a=inicio;b=inicio;
		for(int i=0;i<ln;i++)
		{
			for(int j =0;j<cl;j++)
			{
				System.out.print(a.ele +" ");
				a=a.dir;
			}
			System.out.println();
			b = b.inf;
			a=b;
		}
	}
}