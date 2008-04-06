package elezioni;

public class WrongListaFileFormat extends WrongFileFormat
{
	private static final long serialVersionUID = 1L;

	public WrongListaFileFormat(String message, String fileName, String line)
	{
		super(message, fileName, line);
	}
}
