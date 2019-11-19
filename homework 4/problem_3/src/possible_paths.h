long possiblePathsRecursive(int M, int N) {
    if (M==0 || N==0) {
        return 0;
    }

    if (M+N==2) {
        return 1;
    }

    return possiblePathsRecursive(M-1, N) + possiblePathsRecursive(M, N-1);
}

long possiblePathsIterative(int M, int N) {
    // if there is no grid, there are no paths
    if (M == 0 || N == 0) {
        return 0;
    }
    long paths [M * N]; // stores the number of paths to every location on the grid

    // first row of the grid only has 1 path
    for (int column = 0; column < M; column++) {
        paths[column] = 1;
    }

    // computes the number of paths to every square on the grid
    for (int row = 1; row < N; row++) {
        for (int column = 0; column < M; column++) {
            if (column == 0) {
                paths[M * row] = 1; // first column of the grid only has 1 path
            } else {
                // num of paths found by adding num of paths to top and left adjacent squares
                paths[M * row + column] = paths[M * (row - 1) + column] +
                                          paths[M * row + (column - 1)];
            }
        }
    }
    return paths[M * N - 1]; // returns the total number of paths to the bottom-right corner
}
