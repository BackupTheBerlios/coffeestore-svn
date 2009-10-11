package gfn;

public enum TokenType
{
	ADD 			("+"),
	MUL 			("*"),
	SUB 			("-"),
	DIV 			("/"),
	ASSIGNMENT 		("="),
	VAR 			("var"),
	IF 				("if"),
	FOR				("for"),
	TO 				("to"),
	DO 				("do"),
	END 			("end"),
	PRINT 			("print"),
	ENDSTATEMENT 	(";"),
	NUMBER 			("\\d+"),
	IDENTIFIER 		("\\w+");

	private String tokenValue;
	private boolean needRegex;
	
	private TokenType(String tokenValue)
	{
		this.tokenValue = tokenValue;
		this.needRegex = tokenValue.startsWith("\\");
	}
	
	public String getTokenValue()
	{
		return tokenValue;
	}
	
	public boolean needRegex()
	{
		return needRegex;
	}
}