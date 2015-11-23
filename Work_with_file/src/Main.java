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
        System.setProperty("console.encoding","Cp866");//устранение проблемы вывода русских букв в IntelliJ IDEA
        int numberOfWords = 0;
        Map < Character, Integer > map = new TreeMap();
        System.out.println("Введите имя файла : ");
        Scanner input = new Scanner(System.in);
        String file = input.nextLine();
        try (Scanner in = new Scanner(new File(file + ".txt")))//try с ресурсами. откроет файл и после работы с ним автоматически закроет его
        {
            while(in.hasNext())//пока в потоке есть символы
            {
                String stringFromFile = in.nextLine() + " ";
                int prevSymbol = 0;
                for(int i = 0; i < stringFromFile.length(); i++)
                {
                    if(stringFromFile.charAt(i) != ' ' && stringFromFile.charAt(i) != '—')//если мы встретили разделитель между словами
                    {
                        if((stringFromFile.charAt(i) >= 'а' && stringFromFile.charAt(i) <= 'я') ||
                                (stringFromFile.charAt(i) >= 'А' && stringFromFile.charAt(i) <= 'Я'))//если символ является русской буквой
                            if(map.containsKey(stringFromFile.charAt(i)))//если мы уже встречали рассматриваемый символ
                                map.put(stringFromFile.charAt(i), map.get(stringFromFile.charAt(i)) + 1);
                            else
                                map.put(stringFromFile.charAt(i), 1);
                        prevSymbol = 1;
                    }
                    else if(prevSymbol == 1)//если мы встретили хоть один символ не разделитель, т е встретили новое слово
                    {
                        numberOfWords++;
                        prevSymbol = 0;
                    }
                }
            }
        }
        catch (FileNotFoundException exc)//возникло исключение
        {
            System.out.println(exc.getMessage());//вывод сообщения об ошибке
            System.exit(0);
        }
        String result = "Количество слов равно : ", resultSymbols = "Частотное распределение символов русского алфавита : ";
        System.out.println(result + numberOfWords);
        System.out.println(resultSymbols);
        for(Map.Entry entry : map.entrySet())
        {
            System.out.println(entry.getKey() + " " + entry.getValue());//вывод статистики, отсортированной по буквам
        }
        System.out.println("Git here");
        System.out.println("!");
    }
}