package elezioni.utils;

public class FileReader implements Iterable<String>
{
	private String _fileName;

	public class FileReaderIterator implements java.util.Iterator<String>
	{
		java.io.BufferedReader _reader;
		private String _line;

		public FileReaderIterator(String fileName)
		{
			try
			{
				_reader = new java.io.BufferedReader(new java.io.FileReader(fileName));
			}
			catch (java.io.IOException e)
			{
				_reader = null;
			}
		}
		
		@Override
		public boolean hasNext()
		{
			if (_reader == null)
				return false;
			
			try
			{
				_line = _reader.readLine();
			}
			catch (java.io.IOException e)
			{
				_line = null;
				return false;
			}
			
			if (_line == null)
				return false;
			
			return true;
		}

		@Override
		public String next()
		{
			return _line;
		}

		@Override
		public void remove()
		{

		}
	}
	
	public FileReader(String fileName)
	{
		_fileName = fileName;
	}

	@Override
	public java.util.Iterator<String> iterator()
	{
		return new FileReaderIterator(_fileName);
	}
}
