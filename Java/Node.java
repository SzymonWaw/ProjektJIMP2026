import java.util.Arraylist;
import java.util.List;
import java.util.Hashmap;

public class Graph{
    public List<Node> nodes = new Hashmap<>();
    public String error = ""
}

class Node{
    public int id;
    public int id;
    public double x, y;
    public List<Integer> conn;

    public Node(int id, double x, double y){
        this.id = id;
        this.x = x;
        this.y = y;
        this.conn.add(id) = new ArrayList<>();
    }
}