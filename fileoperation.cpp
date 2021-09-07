#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, i;
    // C语言
    // FILE *pf, *op;
    // pf = fopen("input.txt", "r");
    // op = fopen("output.txt", "w");
    // fscanf(pf, "%d", &n);
    // fprintf(op, "%d\n", n);
    // fclose(pf);
    // fclose(op);

    // C++
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> n;
    out << n;
    in.close();
    out.close();

    return 0;
}