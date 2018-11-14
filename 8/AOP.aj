public aspect AOP
{
	public pointcut ZeroAdded() : call(public void LZWBinfa.Node.setLeftChild(LZWBinfa.Node));
	
	after(): ZeroAdded()
	{
		System.out.println("zero added");
	}
}