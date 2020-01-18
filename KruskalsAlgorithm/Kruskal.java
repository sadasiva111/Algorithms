
import java.util.Scanner;

public class Kruskal {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Number of nodes :");
        int n=input.nextInt();
        System.out.println("Enter the Adjacency Matrix :");
        int[][] matrix =new int[n][n];
        int[] parent = new int[n];
        int min;
        int u=0;
        int v=0;
        int noOfEdges = 1;
        int total =0;

        for (int i = 0; i < n ; i++) {
            parent[i]=0;
            for (int j = 0; j < n ; j++) {
                matrix[i][j]=input.nextInt();
                if (matrix[i][j] == 0) {
                    matrix[i][j]=999;
                }

            }
        }
        while(noOfEdges<n){
            min=999;
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < n ; j++) {
                    if (matrix[i][j] < min) {
                        min = matrix[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
            while (parent[u]!=0){
                u=parent[u];
            }
            while (parent[v]!=0){
                v=parent[v];
            }
            if(v!=u){
                noOfEdges++;
                System.out.println("Edge :"+u+" -- "+v+" Min: "+min);
                total+=min;
                parent[v]=u;
            }
            matrix[u][v]=matrix[v][u]=999;
        }
        System.out.println("The Weight of Minimum Spanning Tree : "+total);
    }
}












