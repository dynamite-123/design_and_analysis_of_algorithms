#include <stdio.h>

int euclid(int m, int n) {
    int r;

    int count = 0;

    while(n) {
        count++;
        r = m % n;
        m = n;
        n = r;
    }
    
    //m is the GCD
    return count;
}

int consec(int m, int n) {
    min = (n < m)? : m : n;

    while(1) {
        count++;
        if (m % min == 0 && n % min == 0) 
            break;

        min--;
    }

    return count;
}

void test_pair(FILE* fp, int a, int b) {
    int e = euclid(a, b);
    int c = consec(a, b);
    int m = modified(a, b);
    fprintf(fp, "%d %d %d %d %d\n", a, b, e, c, m);
}

int modified(int m, int n) {
    int temp, count = 0;

    while (n > 0) {
        if (n > m) {
            temp = m;
            m = n;
            n = temp;
        }

        m = m - n;
        count++;
    }
    return count;
}

void plotter() {
    FILE *fbest = fopen("best_case.txt", "w");
    FILE *fworst = fopen("worst_case.txt", "w");
    FILE *favg = fopen("avg_case.txt", "w");

    if (!fbest || !fworst || !favg) {
        printf("Error opening files.\n");
        return;
    }

    srand(time(NULL));

    for (int i = 10; i <= 1000; i += 50) {
        // Best case: a = b
        test_pair(fbest, i, i);

        // Worst case (Euclid): Fibonacci pairs
        int a = fib(i % 20 + 10);       // fib(10-29)
        int b = fib((i % 20 + 9));      // fib(9-28)
        test_pair(fworst, a, b);

        // Average case: random numbers
        int r1 = rand() % (i + 1);
        int r2 = rand() % (i + 1);
        r1 = (r1 == 0) ? 1 : r1;        // avoid zero
        r2 = (r2 == 0) ? 1 : r2;
        test_pair(favg, r1, r2);
    }

    fclose(fbest);
    fclose(fworst);
    fclose(favg);

    printf("Data saved to best_case.txt, worst_case.txt, avg_case.txt\n");
}
