#include <iostream>
using namespace std;

//Am impartit vectorul in 2 vectori, stanga si dreapta
//Am ordonat vectorul din stanga, dupa regula pe care am gasit-o intre valorile din exemplu,
//am observat ca valorile maxime se pun la jumtatea jumatatii din stanga si la jumatatea jumatatii din dreapta
//apoi restul de valori se pun dupa regula: 
//daca maximul este par, atunci in prima jumtate vom pune doar cifrele pare
//in prima jumatate punem valorile pare in ordine descrescatoare in dreapta jumatatii cu primul maxim
//apoi in stanga, apoi dreapta din nou si stanga din nou, pana ramanem fara valori.
//verificam apoi si jumatatea din stanga
//daca valoarea maxima din vector este impara, adica numarul valorilor din vector este par (de la 0 la n-1)
//folosim acelasi algoritm
//Complexitatea algoritmului este destul de mare, patratica O(n2), parcurgem setul de date, o data in subprogramul sort, iar apoi in sortarea pentru partea dreapta
//si in verificare unde parcurgem a2a jumatate a datelor
//Afisarea datelor are complexitate liniara

void divLeftEven(int arr[], int l, int r, int n, int& k, int& ok)//Sorteaza prima jumatate a vectorului cu valoarea maxima para
{
    int x = n;

    int aux;
    int  mij = (r + l) / 2;


    while (x >= r + 1)
    {
        if ((arr[x] % 2 == 0) && (ok == 1))
        {

            aux = arr[mij + k];
            arr[mij + k] = arr[x];
            arr[x] = aux;
            x--;
            ok = 0;
        }
        else

            if (arr[x] % 2 == 0)
            {
                ok = 1;
                aux = arr[mij - k];
                arr[mij - k] = arr[x];
                arr[x] = aux;
                k = k + 1;
                x--;
            }

        x--;


    }

}

void divLeftOdd(int arr[], int l, int r, int n, int& k, int& ok)//Sorteaza prima jumatate a vectorului cu valoarea maxima impara
{
    int x = n;

    int aux;
    int  mij = (r + l) / 2;


    while (x >= r + 1)
    {
        if ((arr[x] % 2 != 0) && (ok == 1))
        {

            aux = arr[mij + k];
            arr[mij + k] = arr[x];
            arr[x] = aux;
            x--;
            ok = 0;
        }
        else

            if (arr[x] % 2 != 0)
            {
                ok = 1;
                aux = arr[mij - k];
                arr[mij - k] = arr[x];
                arr[x] = aux;
                k = k + 1;
                x--;
            }

        x--;


    }

}

void verifRight(int arr[], int l, int r, int& k)//verifica jumtatea din dreapta
{

    int x = r;
    int aux;

    int mij = l + (r - l) / 2 + 1;
    int ok = 1;
    while ((ok == 1) && (x > mij))
    {
        if (arr[mij - k] > arr[mij + k])
        {
            aux = arr[mij - k];
            arr[mij - k] = arr[mij + k];
            arr[mij + k] = aux;



        }
        else
        {
            ok = 0;
        }
        k++;
        x--;


    }




}

void arrsort(int arr[], int n)//desparte vectorul in 2 jumtati pentru a le sorta si verifica sortarea
{
    int mij = n / 2;
    int k = 1;
    int l = (0 + mij) / 2;
    int r;
    if (n % 2 != 0)
        r = mij + mij / 2 + 1;
    else
        r = mij + mij / 2;
    int ok = 1;

    int aux = arr[r];
    arr[r] = arr[n - 1];
    arr[n - 1] = aux;

    aux = arr[l];
    arr[l] = arr[n];
    arr[n] = aux;
    int i = mij + 1;
    if (n % 2 != 0)
    {
        while (i >= 0)

        {
            if ((arr[i] % 2) != 0)
                divLeftEven(arr, 0, mij, n, k, ok);
            i--;
        }
    }
    else
    {
        while (i >= 0)

        {
            if ((arr[i] % 2) == 0)
                divLeftOdd(arr, 0, mij, n, k, ok);
            i--;
        }
    }
    k = 1;
    verifRight(arr, mij, n, k);


}




static void printArray(int arr[], int n)//afisare
{

    for (int i = 0; i <= n; i++)
        cout << arr[i] << " ";
}





int  main()
{


    int arr[] = { 1, 2, 3, 4, 5 };//vectorul de sortat
    int n = 4;//nr pozitiilor din vector, n+1 este nr valorilor din vector

    arrsort(arr, n);
    printArray(arr, n);
    cout << endl;

    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//vectorul de sortat
    int m = 9;//nr pozitiilor din vector, n+1 este nr valorilor din vector

    arrsort(arr1, m);
    printArray(arr1, m);
    cout << endl;


    return 0;
}
