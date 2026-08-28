int suma(const int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return s;
}

int pares(const int v[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] % 2 == 0)
            c++;
    return c;
}

int maximo(const int v[], int n) {
    int mejor = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > mejor)
            mejor = v[i];
    return mejor;
}