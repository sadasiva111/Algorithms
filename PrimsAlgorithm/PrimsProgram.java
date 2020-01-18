
import java.util.Scanner;

public class PrimsProgram {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Number of vertices present : ");
        int n = input.nextInt();
        int [][] matrix = new int [n][n];
        int [] visited = new int[n];
        int min;
        int u=0;
        int v=0;
        int total=0;
        System.out.println("Enter the Adjacency Matrix : ");
        for (int i = 0; i <n ; i++) {
            visited[i] = 0;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = input.nextInt();
                if (matrix[i][j] == 0) {
                    matrix[i][j] = 999;
                }

            }
        }
        visited[0]=1;
        //startof algo

        for (int counter = 0; counter < n-1; counter++) {
            min= 999;

            for (int i = 0; i < n ; i++) {
                if(visited[i]==1){
                    for (int j = 0; j < n ; j++) {
                        if (visited[j] != 1) {
                            if (min > matrix[i][j]){
                                min = matrix[i][j];
                                u=i;
                                v=j;
                            }
                        }
                    }
                }
            }
            visited[u]=1;
            visited[v]=1;
            total+=min;
            System.out.println("Edge: "+u+" -- "+v+" : Weight: "+min);
        }
        System.out.println("The Weight of minimum spanning tree is : "+total);
    }
}
