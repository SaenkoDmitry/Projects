/**
 * Created by Dmitry on 15.11.2015.
 */
public class Tree {
    Node root;
    public Tree()
    {
        root = null;
    }

    public void insert(int x, Field f)
    {
        if(root == null)
            root = new Node(x, f);
        else
            root = root.insert(x, f);
    }

    public void print()
    {
        if(root != null)
        {
            System.out.println();
            root.print_by_width();
            System.out.println();
        }
    }

    public Field search(int key)
    {
        if(root == null)
            return null;
        else
            return root.searchNode(root, key);
    }

    public void delete(int key)
    {
        root.deleteNode(key);
    }
}