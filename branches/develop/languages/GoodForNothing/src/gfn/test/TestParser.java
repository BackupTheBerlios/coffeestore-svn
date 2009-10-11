package gfn.test;

import java.util.Arrays;
import java.util.Iterator;

import static junit.framework.Assert.*;

import org.junit.Before;
import org.junit.Ignore;
import org.junit.Test;

import gfn.ArithmeticExpressionNode;
import gfn.Parser;
import gfn.PrintNode;
import gfn.Token;
import gfn.TokenType;
import gfn.DeclareVariableNode;

public class TestParser
{
	private ParserObserverMock parserObserver;
	
	Token arithOpAdd;
	Token arithOpMul;
	Token var;
	Token assign;
	Token endStatement;
	Token print;
	
	@Before
	public void setUp()
	{
		parserObserver = new ParserObserverMock();
		
		arithOpAdd = new Token("+", TokenType.ADD);
		arithOpMul = new Token("*", TokenType.MUL);
		var = new Token("var", TokenType.VAR);
		assign = new Token("=", TokenType.ASSIGNMENT);
		endStatement = new Token(";", TokenType.ENDSTATEMENT);
		print = new Token("print", TokenType.PRINT);
	}
	
	private Iterator<Token> createTokenIterator(Token... tokens)
	{
		return Arrays.asList(tokens).iterator();
	}

	@Test
	public void testAddBetweenTwoIntegers() throws Exception
	{
		Token expr1 = new Token("2", TokenType.NUMBER);
		Token expr2 = new Token("3", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(expr1, arithOpAdd, expr2), parserObserver);
		parser.parseExpression();
		
		ArithmeticExpressionNode arithOpNode = parserObserver.getArithExpressionNodes().get(0);
		
		assertSame(expr1, arithOpNode.getLeftExpr());
		assertSame(arithOpAdd, arithOpNode.getArithOp());
		assertSame(expr2, arithOpNode.getRigthExpr());
	}
	
	@Test
	public void testAddBetweenIntegerAndIdentifierFails() throws Exception
	{
		Token expr1 = new Token("2", TokenType.NUMBER);
		Token expr2 = new Token("x", TokenType.IDENTIFIER);
		Parser parser = new Parser(createTokenIterator(expr1, arithOpAdd, expr2), parserObserver);
		try
		{
			parser.parseExpression();
			fail("exception expected");
		}
		catch (Exception exception) {}
	}
	
	@Ignore
	public void testAddBetweenIdentifierAndIntegerFails() throws Exception
	{
		Token expr1 = new Token("x", TokenType.IDENTIFIER);
		Token expr2 = new Token("2", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(expr1, arithOpAdd, expr2), parserObserver);
		try
		{
			parser.parseExpression();
			fail("exception expected");
		}
		catch (Exception exception) {}
	}
	
	@Test
	public void testAddWtihMissingRightNumber() throws Exception
	{
		Token expr1 = new Token("3", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(expr1, arithOpAdd), parserObserver);
		try
		{
			parser.parseExpression();
			fail("exception expected");
		}
		catch (Exception exception) {}
	}
	
	@Test
	public void testAddWtihMissingArithOp() throws Exception
	{
		Token expr1 = new Token("2", TokenType.NUMBER);
		Token expr2 = new Token("3", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(expr1, expr2), parserObserver);
		try
		{
			parser.parseExpression();
			fail("exception expected");
		}
		catch (Exception exception) {}
	}
	
	@Test
	public void testVarWithIdentifierAndNumber() throws Exception
	{
		Token id = new Token("x", TokenType.IDENTIFIER);
		Token value = new Token("3", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(var, id, assign, value, endStatement), parserObserver);
		parser.parseStatement();
		
		DeclareVariableNode variableNode = parserObserver.getDeclareVariableNodes().get(0);
		
		assertSame(id, variableNode.getVariable());
		assertSame(value, variableNode.getValue());
	}
	
	@Test
	public void testPrintNumber() throws Exception
	{
		Token value = new Token("3", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(print, value, endStatement), parserObserver);
		parser.parseStatement();
		
		PrintNode printNode = parserObserver.getPrintNodes().get(0);
		assertSame(value, printNode.getValue());
	}
	
	@Test
	public void testPrintIdentifier() throws Exception
	{
		Token value = new Token("x", TokenType.IDENTIFIER);
		Parser parser = new Parser(createTokenIterator(print, value, endStatement), parserObserver);
		parser.parseStatement();
		
		PrintNode printNode = parserObserver.getPrintNodes().get(0);
		assertSame(value, printNode.getValue());
	}
	
	@Test
	public void testPrintIdentifierTwice() throws Exception
	{
		Token value = new Token("x", TokenType.IDENTIFIER);
		Parser parser = new Parser(createTokenIterator(print, value, endStatement, print, value, endStatement), parserObserver);
		parser.parseStatement();
		
		PrintNode printNode1 = parserObserver.getPrintNodes().get(0);
		assertSame(value, printNode1.getValue());
		PrintNode printNode2 = parserObserver.getPrintNodes().get(1);
		assertSame(value, printNode2.getValue());
	}
	
	@Test
	public void testDeclareVariableAndPrintIdentifier() throws Exception
	{
		Token id = new Token("x", TokenType.IDENTIFIER);
		Token value = new Token("3", TokenType.NUMBER);
		Parser parser = new Parser(createTokenIterator(var, id, assign, value, endStatement, print, id, endStatement), parserObserver);
		parser.parseStatement();
		
		DeclareVariableNode variableNode = parserObserver.getDeclareVariableNodes().get(0);
		assertSame(id, variableNode.getVariable());
		assertSame(value, variableNode.getValue());
		
		PrintNode printNode = parserObserver.getPrintNodes().get(0);
		assertSame(id, printNode.getValue());
	}
}
