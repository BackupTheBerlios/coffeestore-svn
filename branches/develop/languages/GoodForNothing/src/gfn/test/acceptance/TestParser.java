package gfn.test.acceptance;

import gfn.Parser;
import gfn.PrintNode;
import gfn.Token;
import gfn.TokenType;
import gfn.Tokenizer;
import gfn.DeclareVariableNode;
import gfn.test.ParserObserverMock;

import java.io.Reader;
import java.io.StringReader;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TestParser
{
	private ParserObserverMock parserObserver;

	@Before
	public void setUp()
	{
		parserObserver = new ParserObserverMock();
	}
	
	@Test
	public void testParseVarStatement() throws Exception
	{
		String statement = "var x = 3;";
		Reader reader = new StringReader(statement);
		
		Parser parser = new Parser(new Tokenizer(reader), parserObserver);
		parser.parseStatement();
		
		DeclareVariableNode variableNode = parserObserver.getDeclareVariableNodes().get(0);
		assertEquals(new Token("x", TokenType.IDENTIFIER), variableNode.getVariable());
		assertEquals(new Token("3", TokenType.NUMBER), variableNode.getValue());
	}
	
	@Test
	public void testParsePrintIdentifier() throws Exception
	{
		String statement = "print x;";
		Reader reader = new StringReader(statement);
		
		Parser parser = new Parser(new Tokenizer(reader), parserObserver);
		parser.parseStatement();
		
		PrintNode printNode = parserObserver.getPrintNodes().get(0);
		assertEquals(new Token("x", TokenType.IDENTIFIER), printNode.getValue());
	}
	
	@Test
	public void testParseDeclareVariableAndPrintIt() throws Exception
	{
		String statement = "var x = 3; print x;";
		Reader reader = new StringReader(statement);
		
		Parser parser = new Parser(new Tokenizer(reader), parserObserver);
		parser.parseStatement();
		
		DeclareVariableNode variableNode = parserObserver.getDeclareVariableNodes().get(0);
		assertEquals(new Token("x", TokenType.IDENTIFIER), variableNode.getVariable());
		assertEquals(new Token("3", TokenType.NUMBER), variableNode.getValue());
		
		PrintNode printNode = parserObserver.getPrintNodes().get(0);
		assertEquals(new Token("x", TokenType.IDENTIFIER), printNode.getValue());
	}
}
