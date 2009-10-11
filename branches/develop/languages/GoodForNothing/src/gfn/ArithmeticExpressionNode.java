package gfn;

public class ArithmeticExpressionNode
{
	private Token expr1;
	private Token arithOp; 
	private Token expr2;

	public ArithmeticExpressionNode(Token expr1, Token arithOp, Token expr2)
	{
		this.expr1 = expr1;
		this.arithOp = arithOp; 
		this.expr2 = expr2;
	}

	public Token getLeftExpr()
	{
		return expr1;
	}

	public Token getArithOp()
	{
		return arithOp;
	}

	public Token getRigthExpr()
	{
		return expr2;
	}
}
