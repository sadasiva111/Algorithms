import java.util.Scanner;

class SumOfSubsets {
    static int S[],soln[],n,d;
    public static void main(String args[]) {
        S=new int[10];
        soln=new int[10];
        int sum=0;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of elements:");
        n=input.nextInt();
        System.out.println("Enter the set in increasing order:");
        for(int i=1;i<=n;i++)
            S[i]=input.nextInt();
        System.out.print("Enter the value : ");
        d=input.nextInt();
        for(int i=1;i<=n;i++)
            sum=sum+S[i];
        if(sum<d || S[1]>d)
            System.out.println("No Subset Possible");
        else
            SumOfSub(0,0,sum);
    }
    static void SumOfSub(int i,int weight, int total) {
        if(promising(i,weight,total)==true)
            if(weight==d) {
                for(int j=1;j<=i;j++) {
                    if(soln[j]==1)
                        System.out.print(S[j]+" ");
                }
                System.out.println();
            }
            else {
                soln[i+1]=1;
                SumOfSub(i+1,weight+S[i+1],total-S[i+1]);
                soln[i+1]=0;
                SumOfSub(i+1,weight,total-S[i+1]);
            }
    }
    static boolean promising(int i,int weight,int total) {
        return((weight+total>=d)&&(weight==d || weight+S[i+1]<=d));
    }
}