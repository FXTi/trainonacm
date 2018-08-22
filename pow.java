import java.util.*;

import java.io.*;
import java.math.*;

public class Main{

    public static void main(String[] arg){
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        int n = scan.nextInt();
        while(n--!=0){
            int x = scan.nextInt();
            BigInteger ans = new BigInteger("2");
            ans = ans.pow(x);
            System.out.println(ans);
        }
　　　　scan.close();
    }
}