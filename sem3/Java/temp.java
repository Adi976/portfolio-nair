public class TransposeSparseMatrix {

  public static void main(String[] args) {
    int[][] sparseMatrix = {
      { 0, 0, 3, 0, 4 },
      { 0, 0, 5, 7, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 2, 6, 0, 0 },
    };
    int[][] transposedMatrix = transpose(sparseMatrix);
    System.out.println("Original Matrix:");
    printMatrix(sparseMatrix);
    System.out.println("Transposed Matrix:");
    printMatrix(transposedMatrix);
  }

  public static int[][] transpose(int[][] sparseMatrix) {
    int[][] transposedMatrix = new int[sparseMatrix[0].length][sparseMatrix.length];
    for (int i = 0; i < sparseMatrix.length; i++) {
      for (int j = 0; j < sparseMatrix[0].length; j++) {
        transposedMatrix[j][i] = sparseMatrix[i][j];
      }
    }
    return transposedMatrix;
  }

  public static void printMatrix(int[][] matrix) {
    for (int[] row : matrix) {
      for (int element : row) {
        System.out.print(element + " ");
      }
      System.out.println();
    }
  }
}
