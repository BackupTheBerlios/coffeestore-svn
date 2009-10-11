package gfn;

import java.util.Iterator;

public class Parser
{
	private Iterator<Token> tokens;
	private ParserObserver observer;
	
	public Parser(Iterator<Token> tokens, ParserObserver observer)
	{
		this.tokens = tokens;
		this.observer = observer;
	}
	
	//TODO: NUMBER|IDENTIFIER instead of only NUMBER
	// Expr ::= NUMBER|IDENTIFIER [(ADD|MUL|SUB|DIV) NUMBER|IDENTIFIER]
	public void parseExpression() throws Exception
	{
		Token leftToken = getNextNumberToken();
		Token arithOp = getNextArithOpToken();
		Token rigthToken = getNextNumberToken();
			
		observer.onNewNode(new ArithmeticExpressionNode(leftToken, arithOp, rigthToken));
	}

	//TODO: Expr on VAR
	//TODO: Expr on PRINT
	// Statement	::=	VAR IDENTIFIER ASSIGNMENT Expr ENDSTAMENT
	//				|	PRINT Expr ENDSTAMENT
	//				|	Statement ENDSTAMENT {Statement ENDSTAMENT}*
	public void parseStatement() throws Exception
	{
		Token token = getNextToken();
		if (TokenType.VAR == token.getType())
		{
			parseDeclareVariable();
			parseNextStatement();
		}
		else if (TokenType.PRINT == token.getType())
		{
			parsePrint();
			parseNextStatement();
		}
	}

	private void parseNextStatement() throws Exception
	{
		if (tokens.hasNext())
		{
			parseStatement();
		}
	}

	private void parsePrint() throws Exception
	{
		Token tokenValue = getNextToken();
		if (TokenType.NUMBER != tokenValue.getType() && TokenType.IDENTIFIER != tokenValue.getType())
			throw new Exception("expected number or identifier");
		
		eatEndStatementToken();
		
		observer.onNewNode(new PrintNode(tokenValue));
	}

	private void parseDeclareVariable() throws Exception
	{
		Token identifier = getNextIdentifierToken();
		eatAssignmentToken();
		Token number = getNextNumberToken();
		eatEndStatementToken();
		
		observer.onNewNode(new DeclareVariableNode(identifier, number));
	}

	interface NextTokenTypeCheck
	{
		boolean chech(Token token);
	}
	
	private Token getNextToken(NextTokenTypeCheck nextTokenTypeCheck) throws Exception
	{
		if (!tokens.hasNext())
			throw new Exception("expected token");
		
		Token nextToken = tokens.next();
		if (!nextTokenTypeCheck.chech(nextToken))
			throw new Exception(nextTokenTypeCheck.getClass().toString() + " failed");
		
		return nextToken;
	}

	private Token getNextToken() throws Exception
	{
		return getNextToken(new NextTokenTypeCheck()
		{
			public boolean chech(Token nextToken)
			{
				return true;
			}
		});
	}
	
	private Token getNextNumberToken() throws Exception
	{
		return getNextToken(new NextTokenTypeCheck()
		{
			public boolean chech(Token nextToken)
			{
				return nextToken.getType() == TokenType.NUMBER;
			}
		});
	}
	
	private Token getNextIdentifierToken() throws Exception
	{
		return getNextToken(new NextTokenTypeCheck()
		{
			public boolean chech(Token nextToken)
			{
				return nextToken.getType() == TokenType.IDENTIFIER;
			}
		});
	}
	
	private Token getNextArithOpToken() throws Exception
	{
		return getNextToken(new NextTokenTypeCheck()
		{
			public boolean chech(Token nextToken)
			{
				return nextToken.isArithOp();
			}
		});		
	}
	
	private void eatAssignmentToken() throws Exception
	{
		getNextToken(new NextTokenTypeCheck()
		{
			public boolean chech(Token nextToken)
			{
				return nextToken.getType() == TokenType.ASSIGNMENT;
			}
		});
	}

	private void eatEndStatementToken() throws Exception
	{
		getNextToken(new NextTokenTypeCheck()
		{
			public boolean chech(Token nextToken)
			{
				return nextToken.getType() == TokenType.ENDSTATEMENT;
			}
		});
	}
}
