//Is Prime

import java.util.Scanner;

public class Prime {

   
    public static void main(String[] args) {
     
        Scanner scan=new Scanner(System.in);
        
        int n=scan.nextInt();
        
        int i=2;
        boolean flag=false;
        while(i<=n-1){
            
            if(n%i==0){
                flag=true;
            }
            i++;
        }
        
        if(flag==true){
            System.out.println("Number is not prime");
        }
        else{
            System.out.println("Number is prime");
        }
    }
    
}
