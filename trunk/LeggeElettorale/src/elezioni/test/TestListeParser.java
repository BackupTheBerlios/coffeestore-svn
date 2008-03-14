package elezioni.test;

import java.io.File;
import java.io.IOException;
import java.util.Map;

import org.junit.Test;

import elezioni.Lista;
import elezioni.ListeParser;

public class TestListeParser
{
	@Test
	public void test() throws IOException
	{
		ListeParser parser = new ListeParser();
		
		File directory = new File("varie\\listecandidati\\src");
		for (File file : directory.listFiles())
		{
			String fileName = file.getName();
			if (!fileName.equals(".svn") && !fileName.equals("trentino_senato.txt") && !fileName.equals("valle_camera.txt") && !fileName.equals("valle_senato.txt"))
			{
				System.out.println(file.getName());
				parseRegione(parser, file.getAbsolutePath());
			}
		}
		
		//parser.parseRegione("varie\\listecandidati\\src\\calabria_camera.txt");
	}

	private void parseRegione(ListeParser parser, String regione) throws IOException
	{
		Map<String, Lista> liste = parser.parseRegione(regione);
		for (String partito : liste.keySet())
		{
			Lista lista = liste.get(partito);
		}
	}
}
