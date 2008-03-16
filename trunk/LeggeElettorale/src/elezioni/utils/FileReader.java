package elezioni.utils;

import java.io.File;
import java.io.FileNotFoundException;

public class FileReader implements Iterable<String>
{
	private String _fileName;

	public class FileReaderIterator implements java.util.Iterator<String>
	{
		private java.io.BufferedReader _reader;
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
	
	public FileReader(String fileName) throws FileNotFoundException
	{
		_fileName = fileName;
		tryOpen();
	}

	private void tryOpen() throws FileNotFoundException
	{
		File file = new File(_fileName);
		if (!file.exists() || file.isDirectory())
			throw new FileNotFoundException(_fileName);	
	}

	@Override
	public java.util.Iterator<String> iterator()
	{
		return new FileReaderIterator(_fileName);
	}
}
