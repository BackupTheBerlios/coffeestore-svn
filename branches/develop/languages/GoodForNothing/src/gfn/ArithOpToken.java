package gfn;

public class ArithOpToken extends Token
{
	public static final ArithOpToken add = new ArithOpToken("+");
	public static final ArithOpToken mul = new ArithOpToken("*");
	public static final ArithOpToken sub = new ArithOpToken("-");
	public static final ArithOpToken div = new ArithOpToken("/");
	
	public ArithOpToken(String value)
	{
		super(value);
	}
}
