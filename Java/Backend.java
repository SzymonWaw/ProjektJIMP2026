import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;
import java.io.Bufferedreader;
import java.io.InputStreamReader;

public class Backend{
    public Graph importGraph(String filename) {
        Graph graph = new Graph();
        String fileNode = "wynik.txt";
        String fileEdge = "edge.txt";

        boolean success = runC(fileNode, fileEdge, graph);

        if (success) {
            readNodes(fileNode, graph);
            readEdges(fileEdge, graph);
            cleanup(fileNode, fileEdge);
        }
        return graph;

    }

    private boolean runC(String fileNode, String fileEdge, Graph graph) {
        try{
            Processbuilder builder = new Processbuilder("ProjektJIMP2026/graf.exe", "0", fileNode, fileEdge);
            Process process = builder.start();

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            Stringbuilder output = new Stringbuilder();
            String line;
            while((line = reader.readline()) != null){
                output.append(line).append("\n");
            }
            int ExitC = process.waitfor();
            if(ExitC != 0){
                graph.error = output.toString().trim();
                return false;
            }
        }
        catch (IOException | InterruptedException e) {
            graph.errorMessage = "Blad komunikacji z C: " + e.getMessage();
            return false;
        }
    }
}
    private void readNodes(String nodes_path, Graph graph)
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
        catch(Exception error){
            graph.error("Nie udalo sie wczytac wierzcholkow");
        }
    }
    private void readEdges(String edges_path, Graph graph)
    {
        File file = new File(edges_path);
        try BufferedReader br = new BufferedReader(new FileReader(file));
            String line;
            while ((line = br.read.line()) != null){
            String[] parts = line.trim().split(" \\s+");
            int Aid = Integer.parseInt(parts[0]);
            int Bid = Integer.parseInt(parts[1]);
            graph.nodes.get(Aid).connected.add(Bid);
            graph.nodes.get.(Bid).connected.add(Aid);
            }
        catch (Exception error){
            graph.error = "Nie udalo sie wczytac krawedzi"
        }
    }

    private void cleanup(String fileNode, String fileEdge) {
        new File(fileNode).delete();
        new File(fileEdge).delete();
    }
}