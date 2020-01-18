import java.util.Scanner;

public class MColoringProblem {

    public static void solve(int[][] graph, int max) {
        int[] sol = new int[graph.length];
        if (solve(0, 1, graph, sol, max))
            printSol(sol);
        else
            System.out.println("Not possible.");
    }

    private static boolean solve(int index, int color, int[][] graph, int[] sol, int max) {
        if (index == sol.length - 1) {
            sol[index] = color;
            return true;
        }
        sol[index] = color;
        for (int i = 0; i < graph.length; i++) {
            if (graph[index][i] == 1 && sol[i] == 0) {
                int tempC = 1;
                while (!isValidColor(tempC, i, graph, sol)) {
                    tempC++;
                }
                if (tempC <= max) {
                    if (!solve(i, tempC, graph, sol, max))
                        sol[i] = 0; // This is the backtracking point.
                    else
                        return true;
                }
            }
        }
        return false;
    }

    public static boolean isValidColor(int color, int index, int[][] graph, int[] sol) {
        for (int i = 0; i < graph.length; i++) {
            if (graph[index][i] == 1) {
                if (sol[i] == color)
                    return false;
            }
        }
        return true;
    }

    private static void printSol(int[] sol) {
        for (int s : sol)
            System.out.print(s + " ");
    }

    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        System.out.print("Number of Vertices in the graph : ");
        int n = input.nextInt();
        int[][] graph = new int[n][n];
        System.out.println("Enter the Adjacency Matrix :");
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = input.nextInt();
            }
        }
	System.out.println("Solution : ");
        solve(graph, 3);
    }
}
