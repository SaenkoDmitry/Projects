/**
 * Created by Dmitry on 14.12.2015.
 */
public class HashTable {
    private DataItem[] hashArray;
    private int arraySize;
    DataItem nonItem;
    public HashTable(int size)
    {
        arraySize = size;
        hashArray = new DataItem[arraySize];
        nonItem = new DataItem(-1, null);
    }
    public int hashFunc(int key)
    {
        return abs(key % arraySize);
    }

    private int abs(int i) {
        if(i < 0)
            return i *-1;
        else
            return i;
    }

    public void insert(DataItem item)
    {
        int key = item.getKey();
        int hashVal = hashFunc(key);
        while(hashArray[hashVal] != null &&
                hashArray[hashVal].getKey() != -1)
        {
            ++hashVal;
            hashVal %= arraySize;
        }
        hashArray[hashVal] = item;
    }
    public DataItem delete(int key)
    {
        int hashVal = hashFunc(key);
        while(hashArray[hashVal] != null)
        {
            if(hashArray[hashVal].getKey() == key)
            {
                DataItem temp = hashArray[hashVal];
                hashArray[hashVal] = nonItem;
                return temp;
            }
            ++hashVal;
            hashVal %= arraySize;
        }
        return null;
    }
    public void displayTable()
    {
        System.out.println();
        System.out.println("-----------------------------------------------------------");
        System.out.println("Hash Table: \n");
        for(int j=0; j<arraySize; j++)
        {
            if(hashArray[j] != null) {
                System.out.println(hashArray[j].getKey() + " ");
                hashArray[j].getField().print();
            }
        }
        System.out.println();
        System.out.println("-----------------------------------------------------------");
    }
    public DataItem find(int key)
    {
        int hashVal = hashFunc(key);
        while(hashArray[hashVal] != null)
        {
            if(hashArray[hashVal].getKey() == key)
                return hashArray[hashVal];
            ++hashVal;
            hashVal %= arraySize;
        }
        return null;
    }
}