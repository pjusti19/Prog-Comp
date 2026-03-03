#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

void mergeSort(vector<int> numeros, int inicio, int fim){

    if(inicio >=  fim)
        return;

    int meio = (inicio + fim) / 2;
    mergeSort(numeros, inicio, meio);
    mergeSort(numeros, meio+1, fim);
    merge(numeros, inicio, fim);

}

void merge(vector<int>& numeros, int inicio, int fim){

}




int main(){



}