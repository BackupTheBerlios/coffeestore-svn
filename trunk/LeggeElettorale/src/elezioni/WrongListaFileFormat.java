package elezioni;

import java.io.IOException;

public class WrongListaFileFormat extends IOException
{
	public WrongListaFileFormat(String message)
	{
		super(message);
	}

	private static final long serialVersionUID = 1L;
}
