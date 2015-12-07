import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 * Created by Dmitry on 15.11.2015.
 */
public class Node {
    static int t = 2;
    int keys[];
    Field field[];
    Node nodes[];
    int n = 0;
    boolean isleaf;
    Queue < Node > treeWidth = new LinkedList<>();

    public Node()
    {
        keys = new int[2 * t];
        field = new Field[2 * t];
        nodes = new Node[2 * t + 1];
        n = 0;
        isleaf = true;
    }

    public Node(int x, Field f)
    {
        keys = new int[2 * t];
        field = new Field[2 * t];
        nodes = new Node[2 * t + 1];
        n = 1;
        isleaf = true;
        keys[0] = x;
        field[0] = f;
    }

    public Node insert(int x, Field f)
    {
        Node root = this;
        if(root.n != (2 * t - 1))
        {
            root = root.insertNonFull(x, f);
        }
        else
        {
            Node s = new Node();
            s.isleaf = false;
            s.n = 0;
            Node temp = root;
            root = s;
            root.nodes[0] = temp;
            root = root.splitNode(0);
            root = root.insertNonFull(x, f);
        }
        return root;
    }

    private Node insertNonFull(int x, Field f)
    {
        Node r = this;
        int i = r.n - 1;
        if(r.isleaf)
        {
            while((i >= 0) && (x < r.keys[i]))
            {
                r.keys[i + 1] = r.keys[i];
                r.field[i + 1] = r.field[i];
                i--;
            }
            r.keys[i + 1] = x;
            r.field[i + 1] = f;
            r.n++;
        }
        else
        {
            while((i >= 0) && (x < r.keys[i]))
            {
                i--;
            }
            i++;
            if(r.nodes[i].n == (2 * t - 1))
            {
                r = r.splitNode(i);
                if(x > r.keys[i])
                {
                    i++;
                }
            }
            r.nodes[i] = r.nodes[i].insertNonFull(x, f);
        }
        return r;
    }
    private Node splitNode(int child)
    {
        Node r = this;
        Node temp = new Node();
        Node tempChild = r.nodes[child];
        temp.isleaf = tempChild.isleaf;
        temp.n = t - 1;
        for (int i = 0; i <= (t - 1); i++) {
            temp.keys[i] = tempChild.keys[i + t];
            temp.field[i] = tempChild.field[i + t];
        }
        if(!tempChild.isleaf)
            for (int i = 0; i <= t; i++) {
                temp.nodes[i] = tempChild.nodes[i + t];
            }
        tempChild.n = t - 1;
        for(int i = r.n; i >= child + 1; i--)
        {
            r.nodes[i + 1] = r.nodes[i];//?
        }
        r.nodes[child + 1] = temp;
        for(int i = r.n - 1; i >= child; i--)
        {
            r.keys[i + 1] = r.keys[i];
            r.field[i + 1] = r.field[i];
        }
        r.keys[child] = tempChild.keys[t - 1];
        r.field[child] = tempChild.field[t - 1];
        r.n++;
        return r;
    }

    public void print_klp()
    {
        Node root = this;
        if(root != null)
        {
            int i = 0;
            String temp = "";
            while(i <= root.n - 1)
            {
                if(temp != "")
                {
                    temp = temp + "," + root.keys[i];
                }
                else
                {
                    temp = temp + root.keys[i];
                }
                i++;
            }
            temp = "\n(" + temp + ")";// + "{ " + "n = " + root.n + ", isleaf = " + root.isleaf + " }";
            System.out.print(temp);
            int j = 0;
            if(root.nodes[j] != null)
            {
                System.out.print("\n&");
                while(j <= root.n)
                {
                    root.nodes[j].print_klp();
                    j++;
                }
                System.out.print("\n%");
            }
        }
    }

    public void print_by_width()
    {
        Node root = this;
        if(root != null)
        {
            int prev = 1, cur = 0;
            treeWidth.add(root);
            while(!treeWidth.isEmpty())
            {
                int i = 0, j = 0;
                if(treeWidth.element().nodes[j] != null)
                {
                    while(j <= treeWidth.element().n)
                    {
                        root = treeWidth.element().nodes[j];
                        treeWidth.add(root);
                        j++;
                    }
                }
                String temp = "";
                while(i <= treeWidth.element().n - 1)
                {
                    if(temp != "")
                        temp = temp + "," + treeWidth.element().keys[i];
                    else
                        temp = temp + treeWidth.element().keys[i];
                    i++;
                }
                temp = "\n(" + temp + ")";// + "{ " + "n = " + treeWidth.element().n + ", isleaf = " + treeWidth.element().isleaf + " }";
                System.out.print(temp);
                prev--;
                cur += j;
                if(prev == 0)
                {
                    prev = cur;
                    cur = 0;
                    System.out.println();
                }
                treeWidth.remove();
            }
        }
    }
    public Field searchNode (Node root, int key)
    {
        int i = 0;
        if(root != null) {
            while (i <= root.n - 1 && root.keys[i] < key) {
                i = i + 1;
            }
            if (i <= root.n - 1 && root.keys[i] == key) {
                return root.field[i];
            }
            if (root.isleaf) {
                return null;
            } else {
                return searchNode(root.nodes[i], key);
            }
        }
        else
            return null;
    }

    public void deleteNode(int key)
    {
        Node root = searchNodeR(this, key);
        if(root.isleaf)
        {
            for (int i = 0; i < root.n; i++) {
                if(root.keys[i] == key)
                {
                    for (int j = 0; j < root.n - 1; j++) {
                        root.keys[i] = root.keys[i + 1];
                    }
                    root.n--;
                }
            }
        }
        else
        {

        }
    }
    public Node searchNodeR (Node root, int key)
    {
        int i = 0;
        if(root != null) {
            while (i <= root.n - 1 && root.keys[i] < key) {
                i = i + 1;
            }
            if (i <= root.n - 1 && root.keys[i] == key) {
                return root;
            }
            if (root.isleaf) {
                return null;
            } else {
                return searchNodeR(root.nodes[i], key);
            }
        }
        else
            return null;
    }
}
