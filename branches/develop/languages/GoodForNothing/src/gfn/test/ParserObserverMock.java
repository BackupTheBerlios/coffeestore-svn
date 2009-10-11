package gfn.test;

import java.util.ArrayList;

import gfn.ArithmeticExpressionNode;
import gfn.DeclareVariableNode;
import gfn.ParserObserver;
import gfn.PrintNode;

public class ParserObserverMock implements ParserObserver
{
	private ArrayList<ArithmeticExpressionNode> arithExpressionNodes;
	private ArrayList<DeclareVariableNode> declareVariableNodes;
	private ArrayList<PrintNode> printNodes;

	public ParserObserverMock()
	{	
		arithExpressionNodes = new ArrayList<ArithmeticExpressionNode>();
		declareVariableNodes = new ArrayList<DeclareVariableNode>();
		printNodes = new ArrayList<PrintNode>();
	}
	
	@Override
	public void onNewNode(ArithmeticExpressionNode arithExpressionNode)
	{
		arithExpressionNodes.add(arithExpressionNode);
	}

	@Override
	public void onNewNode(DeclareVariableNode declareVariableNode)
	{
		declareVariableNodes.add(declareVariableNode);
	}

	@Override
	public void onNewNode(PrintNode printNode)
	{
		printNodes.add(printNode);
	}

	public ArrayList<ArithmeticExpressionNode> getArithExpressionNodes()
	{
		return arithExpressionNodes;
	}

	public ArrayList<DeclareVariableNode> getDeclareVariableNodes()
	{
		return declareVariableNodes;
	}

	public ArrayList<PrintNode> getPrintNodes()
	{
		return printNodes;
	}
}
