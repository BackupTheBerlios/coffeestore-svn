package elezioni.test;

import java.io.File;
import java.io.IOException;
import java.util.Map;

import org.junit.Test;

import elezioni.Lista;
import elezioni.ListeParser;
import elezioni.PartitoEnum;

public class TestListeParser
{
	@Test
	public void test() throws IOException
	{
		ListeParser parser = new ListeParser();
		
		File directory = new File("varie/listecandidati/src");
		for (File file : directory.listFiles())
		{
			String fileName = file.getName();
			if (!fileName.equals(".svn"))
			{
				parseRegione(parser, file.getAbsolutePath());
			}
		}
	}

	private void parseRegione(ListeParser parser, String regione) throws IOException
	{
		Map<PartitoEnum, Lista> liste = parser.parseCollegio(regione);
		for (PartitoEnum partito : liste.keySet())
		{
			Lista lista = liste.get(partito);
		}
	}
}
