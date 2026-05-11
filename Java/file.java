import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;
import java.util.Bufferedreader;

public class read_nodes
{
    public static void read(String nodes_path, Graph graph)
    {
        File file = new File(nodes_path);
        try (Scanner scanner = new Scanner(file)
        {
            Scanner.useLocale(Locale.US);

            while(Scanner.hasNext())
            {
                int id = scanner.nextInt();
                double x = scanner.nextDouble();
                double y = scanner.nextDouble();

                node.nodes.put(new Node(id, x, y));
            }
        }
    catch(Exception error);
        {
            graph.error("Nie udalo sie wczytac wierzcholkow");
        }
}

public class read_edges(String edges_path, Graph graph)
{
    File file = new File(edges_path);
    try BufferedReader br = new BufferedReader(new FileReader(file));
        String line;
        while ((line = br.read.line()) != null){
        String}
        }
}