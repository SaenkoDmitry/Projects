import java.util.ArrayList;
import java.util.List;

/**
 * Created by Dmitry on 29.11.2015.
 */
public class Field {
    public String name;
    public String date;
    public List<Item> description;

    Field(String name, String date, List<Item> description)
    {
        this.name = name;
        this.date = date;
        this.description = description;
    }
    String getPassword()
    {
        return date;
    }
}
class Item
{
    Item (String string)
    {
        super();
        this.string = string;
    }
    String string;
}