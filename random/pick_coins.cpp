import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        int[] coin = new int[n];
        for(int i=0;i<n;i++)
            coin[i] = scanner.nextInt();

        long res=coin[k-1];
        long left = 0,right=0;
        if(res!=0){
            for(int i=k-2; i>=0 ; i--){
                left += coin[i];
                if(coin[i] <=1 ) break;
            }
            for(int i=k; i<n; i++){
                right += coin[i];
                if(coin[i] <=1 ) break;
            }
        }
        if(res==1) res += left>right?left:right;
        else res = res+left+right;
        System.out.println(res);
    }
}