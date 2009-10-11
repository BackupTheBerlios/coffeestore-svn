package gfn.test;

import org.junit.Test;
import static org.junit.Assert.*;
import gfn.Token;
import gfn.TokenType;

public class TestToken
{
	@Test
	public void testEqualsWithDifferentType()
	{
		Token token = new Token("x", TokenType.IDENTIFIER);
		
		assertFalse(token.equals("x"));
	}
	
	@Test
	public void testEqualsWithDifferentValue()
	{
		Token x = new Token("x", TokenType.IDENTIFIER);
		Token y = new Token("y", TokenType.IDENTIFIER);
		
		assertFalse(x.equals(y));
	}

	@Test
	public void testEquals()
	{
		Token x1 = new Token("x", TokenType.IDENTIFIER);
		Token x2 = new Token("x", TokenType.IDENTIFIER);
		
		assertTrue(x1.equals(x2));
	}
	
	@Test
	public void testIntegerAndStringTokenAreNotEqual()
	{
		Token x1 = new Token("12", TokenType.IDENTIFIER);
		Token x2 = new Token("12", TokenType.NUMBER);
		
		assertFalse(x1.equals(x2));
	}
	
	@Test
	public void testIsArithOp()
	{
		assertTrue(new Token("+", TokenType.ADD).isArithOp());
		assertTrue(new Token("-", TokenType.SUB).isArithOp());
		assertTrue(new Token("*", TokenType.MUL).isArithOp());
		assertTrue(new Token("/", TokenType.DIV).isArithOp());
	}

	@Test
	public void testIsArithOpFails()
	{
		assertFalse(new Token("as", TokenType.IDENTIFIER).isArithOp());
	}
}
