package elezioni;

public class WrongNumParlamentariFileFormat extends WrongFileFormat
{
	private static final long serialVersionUID = 1L;
	
	public WrongNumParlamentariFileFormat(String fileName, String line)
	{
		super("WrongNumParlamentariFileFormat", fileName, line);
	}
}
