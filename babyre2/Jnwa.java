import java.lang.String;
import java.util.Scanner;
public class Jnwa{
    public static void main(String[] args)
    {
        int i;
        String flag;
        System.out.print("请输入CTFTQL:");
        Scanner input = new Scanner(System.in);
        flag = input.nextLine();
        char[] str1 ={'{','y','i','_','q','i','_'};
        char[] str2 = {'W','Y','D','T','Q'};
        String str3 = "happy}";
        String a = new String(str1);
        if(flag.equals("CTFTQL"))
        {
            for (i = 0; i < 5; i++)
            {
                if (str2[i] == 'W')
                {
                    str2[i] = 'J';
                    continue;
                }
                if (str2[i] == 'Y')
                {
                    str2[i] = 'N';
                    continue;
                }
                if (str2[i] == 'D')
                {
                    str2[i] = 'C';
                    continue;
                }
                if (str2[i] == 'T')
                {
                    str2[i] = 'T';
                    continue;
                }
                if (str2[i] == 'Q')
                {
                    str2[i] = 'F';
                    continue;
                }
            }
        }
        String b = String.valueOf(str2);
        System.out.print(b+a+str3);

    }
}