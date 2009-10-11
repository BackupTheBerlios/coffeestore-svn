package gfn;

public class DeclareVariableNode extends StatementNode
{
	private Token variable;
	private Token value;
	
	public DeclareVariableNode(Token variable, Token value)
	{
		this.variable = variable;
		this.value = value;
	}
	
	public Token getVariable()
	{
		return variable;
	}
	
	public Token getValue()
	{
		return value;
	}
}
