class No{
	int ele;
	No inf,sup,dir,esq;
	No()
	{
		this(0);
	}
	No(int ele)
	{
		this(ele, null, null, null, null);
	}
	No(int ele, No dir, No esq, No inf, No sup)
	{
		this.ele=ele;
		this.dir=dir;
		this.esq=esq;
		this.sup=sup;
		this.inf=inf;
	}
}
