package gfn;

public class Token
{
	public enum Type
	{
		ADD,
		MUL,
		SUB,
		DIV,
		ASSIGNMENT,
		STRING,
		NUMBER,
		VAR,
		IDENTIFIER,
		IF,
		FOR,
		TO,
		DO,
		END,
		PRINT,
		ENDSTATEMENT,
	}

	private String value;
	private Type type;
	
	public Token(String value, Type type)
	{
		this.value = value;
		this.type = type;
	}
	
	public String getValue()
	{
		return value;
	}
	
	public Type getType()
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
}
