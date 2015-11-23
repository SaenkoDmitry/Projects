/**
 * Created by Dmitry on 16.11.2015.
 */
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.*;
import java.io.File;
import java.lang.String;


public class Main {
    public static void main (String args[])
    {
        System.setProperty("console.encoding","Cp866");//���������� �������� ������ ������� ���� � IntelliJ IDEA
        int numberOfWords = 0;
        Map < Character, Integer > map = new TreeMap();
        System.out.println("������� ��� ����� : ");
        Scanner input = new Scanner(System.in);
        String file = input.nextLine();
        try (Scanner in = new Scanner(new File(file + ".txt")))//try � ���������. ������� ���� � ����� ������ � ��� ������������� ������� ���
        {
            while(in.hasNext())//���� � ������ ���� �������
            {
                String stringFromFile = in.nextLine() + " ";
                int prevSymbol = 0;
                for(int i = 0; i < stringFromFile.length(); i++)
                {
                    if(stringFromFile.charAt(i) != ' ' && stringFromFile.charAt(i) != '�')//���� �� ��������� ����������� ����� �������
                    {
                        if((stringFromFile.charAt(i) >= '�' && stringFromFile.charAt(i) <= '�') ||
                                (stringFromFile.charAt(i) >= '�' && stringFromFile.charAt(i) <= '�'))//���� ������ �������� ������� ������
                            if(map.containsKey(stringFromFile.charAt(i)))//���� �� ��� ��������� ��������������� ������
                                map.put(stringFromFile.charAt(i), map.get(stringFromFile.charAt(i)) + 1);
                            else
                                map.put(stringFromFile.charAt(i), 1);
                        prevSymbol = 1;
                    }
                    else if(prevSymbol == 1)//���� �� ��������� ���� ���� ������ �� �����������, � � ��������� ����� �����
                    {
                        numberOfWords++;
                        prevSymbol = 0;
                    }
                }
            }
        }
        catch (FileNotFoundException exc)//�������� ����������
        {
            System.out.println(exc.getMessage());//����� ��������� �� ������
            System.exit(0);
        }
        String result = "���������� ���� ����� : ", resultSymbols = "��������� ������������� �������� �������� �������� : ";
        System.out.println(result + numberOfWords);
        System.out.println(resultSymbols);
        for(Map.Entry entry : map.entrySet())
        {
            System.out.println(entry.getKey() + " " + entry.getValue());//����� ����������, ��������������� �� ������
        }
        System.out.println("Git here");
        System.out.println("!");
    }
}