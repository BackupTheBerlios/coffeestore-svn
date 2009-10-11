package gfn;

public class Token
{
	private String value;
	private TokenType type;
	
	public Token(String value, TokenType type)
	{
		this.value = value;
		this.type = type;
	}
	
	public String getValue()
	{
		return value;
	}
	
	public TokenType getType()
	{
		return type;
	}


	@Override
	public boolean equals(Object obj)
	{
		if (!getClass().equals(obj.getClass()))
		{
			return false;
		}
		
		Token token = (Token) obj;
		return value.equals(token.value) && type == token.type;
	}

	@Override
	public String toString()
	{
		return String.format("%s|%s|", value, type.toString());
	}
	
	public boolean isArithOp()
	{
		TokenType tokenType = getType();
		return (tokenType == TokenType.ADD || tokenType == TokenType.SUB || tokenType == TokenType.MUL || tokenType == TokenType.DIV);
	}
}
