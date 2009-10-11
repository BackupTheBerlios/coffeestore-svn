package gfn;

public class PrintNode extends StatementNode
{
	private Token value;
	
	public PrintNode(Token value)
	{
		this.value = value;
	}

	public Token getValue()
	{
		return value;
	}
}
