package gfn;

public interface ParserObserver
{
	void onNewNode(ArithmeticExpressionNode arithExpressionNode);
	void onNewNode(DeclareVariableNode declareVariableNode);
	void onNewNode(PrintNode printNode);
}
