import java.util.Scanner;

public class Floyds {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number of vertices:");
        int N = input.nextInt();
        int[][] M = new int[N][N];
        int [][] P = new int[N][N];
        System.out.println("Enter the Adjacency Matrix :");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                M[i][j] = input.nextInt();
                if (M[i][j] == 0 && i != j)
                    M[i][j] = 999;
            }
        }
        //Algorithm code
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // to keep track.;
                    if (M[i][k] + M[k][j] < M[i][j]) {
                        M[i][j] = M[i][k] + M[k][j];
                        P[i][j] = k;
                    }
                }
            }
        }
        //Printing the matrix
        System.out.println("Shortest Path Matrix.");
        System.out.print("\n\t");
        for (int j = 0; j < N; j++) {
            System.out.print(j + "\t");
        }
        System.out.println();
        for (int j = 0; j < 50; j++) {
            System.out.print("-");
        }
        System.out.println();
        for (int i = 0; i < N; i++) {
            System.out.print(i + " |\t");
            for (int j = 0; j < N; j++) {
                System.out.print(M[i][j]);
                System.out.print("\t");
            }
            System.out.println("\n");
        }
        System.out.println("\n");
    }
}