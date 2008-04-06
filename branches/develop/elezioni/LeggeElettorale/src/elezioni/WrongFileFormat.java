package elezioni;

import java.io.IOException;

public class WrongFileFormat extends IOException
{
	private static final long serialVersionUID = 1L;
	
	private String _fileName;
	private String _line;

	public WrongFileFormat(String message, String fileName, String line)
	{
		super(message);
		_fileName = fileName;
		_line = line;
	}

	public String toString()
	{
		return String.format("%s fileName <%s> line <%s>", super.toString(), _fileName, _line);
	}
}