package elezioni.test;

import static org.junit.Assert.*;
import org.junit.Test;

import elezioni.Circoscrizione;
import elezioni.Lista;
import elezioni.Parlamentare;
import elezioni.Partito;
import elezioni.Premier;

import java.io.*;
import java.net.*;

import javax.swing.text.html.*;
import javax.swing.text.BadLocationException;

public class TestPartito 
{
	@Test
	public void test()
	{
		Premier veltroni = new Premier("Walter", "Veltroni");
		Partito pd = new Partito("Partito Democratico", veltroni);
		Circoscrizione umbria1 = new Circoscrizione("Umbria1");
		Circoscrizione marche1 = new Circoscrizione("Marche1");
		Circoscrizione toscana1 = new Circoscrizione("Toscana1");
		Circoscrizione toscana2 = new Circoscrizione("Toscana2");
		Lista listaUmbria1Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Fabio", "Lombardelli"));
		Lista listaMarche1Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Guido", "Ranzuglia"));
		Lista listaToscana1Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Massimo", "Ceccherini"));
		Lista listaToscana2Pd = new Lista();
		listaUmbria1Pd.add(new Parlamentare("Alessandro", "Paci"));
		
		pd.addToCamera(umbria1, listaUmbria1Pd);
		pd.addToCamera(marche1, listaMarche1Pd);
		pd.addToCamera(toscana1, listaToscana1Pd);
		pd.addToCamera(toscana2, listaToscana2Pd);
		
		assertEquals(pd.getListeCamera(umbria1), listaUmbria1Pd);
	}
	
    public static void getLinks(String uriStr) throws URISyntaxException, IOException, BadLocationException 
    {
   
            // Create a reader on the HTML content
            URL url = new URI(uriStr).toURL();
            URLConnection conn = url.openConnection();
            Reader rd = new InputStreamReader(conn.getInputStream());
    
            // Parse the HTML
            HTMLEditorKit kit = new HTMLEditorKit();
            HTMLDocument doc = (HTMLDocument)kit.createDefaultDocument();
            kit.read(rd, doc, 0);
    
            // Find all the A elements in the HTML document
            HTMLDocument.Iterator it = doc.getIterator(HTML.Tag.A);
            while (it.isValid()) {
                System.out.println(it.toString());
            	//SimpleAttributeSet s = (SimpleAttributeSet)it.getAttributes();
//    
//                String link = (String)s.getAttribute(HTML.Attribute.HREF);
//                if (link != null) {
//                    // Add the link to the result list
//                    result.add(link);
//                }
//                it.next();
           }

    }
	
	public static BufferedReader read(String url) throws Exception
	{
		return new BufferedReader(
			new InputStreamReader(
				new URL(url).openStream()));
	}
	
	@Test
	public void testConnection() throws Exception
	{
		//BufferedReader reader = read("http://www.tocqueville.it/politiche2008/default.htm");
		getLinks("http://www.tocqueville.it/politiche2008/default.htm");
//		String line = reader.readLine();
//		StringBuffer stringdocument = new StringBuffer(line);
//		while (line != null) 
//		{
//			line = reader.readLine();
//			stringdocument.append("\n").append(line);
//		}
		
		
	}
}

