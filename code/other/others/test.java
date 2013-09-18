import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class test {
    
    public static String[] a = {"a","b","c"}; 
    public static int count;
    
    public static void sub(List<String> list , String prefix) {
        if(list == null || list.size() == 0) 
            return;
        for(int i = 0; i < list.size(); i++) {
            System.out.println("-------------");
            List<String> temp = new ArrayList<String>(list);
            for (String s : temp) {
                System.out.print(s + " ");
            }
            String str = temp.remove(i);
            for(int j = 0; j < i;j++) 
                temp.remove(0);
            System.out.println(prefix + str + "   count: " + ++count);
            sub(temp, prefix + str);
        }
    }
    
    public static void main(String[] args) {
        List<String> list = Arrays.asList(a);
        sub(list, "");
    }
    
}
