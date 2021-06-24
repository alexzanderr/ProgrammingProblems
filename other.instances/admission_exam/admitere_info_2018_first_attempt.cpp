#include <iostream>
#include <cstdio>
using namespace std;

// REZOLVAREA DE MAI JOS ESTE EXACT DUPA CERINTELE DATE IN PROBLEMA


void citire(int &l, char str[]) // aici am implementat functia de citire pentru sirul dat in problema
{
    do
    {
        l++;
        str[l] = getchar();   // citirea se efectueaza cu getchar si valoarea este introdusa in sir la indexul respectiv
    }
    while(str[l] != '\n'); // daca valoarea introdusa este ENTER, citirea se opreste
}

void print(int l, char str[]) // functia pentru afisarea sirului pe ecran
{
    for(int i = 0; i < l; i++)
    {
        cout << str[i];
    }
}

//void printMAT(int rand, int col, char **str)
//{
//    for(int i = 0; i < rand; i++)
//    {
//        for(int j = 0; j < col; j++)
//        {
//            cout << str[i][j];
//        }
//        cout << endl;
//    }
//}

int main()
{
    //din pacate am citit lmax dupa sir pentru ca avea niste rezultate dubioase daca faceam invers

    char text[10000][23] = {0}; // matricea in care se va introduce sirul dupa criteriile date
    int rand = 0; // numarul de linii ale matricei

    //const char cst[] = "PROBLEMA DE LA EXAMEN NU MI SE PARE FOARTE GREU DE REZOLVAT IN TIMPUL ACORDAT.";

    int length = -1, lmax; // lungimea sirului si limita pentru delimitare pe randuri
    char str[10000]; // sirul in care introducem textul
    citire(length, str); // citim sirul

    cin >> lmax; // citim L

//    print(length, str);
//    cout << endl;

    char cuv1[100]; // un sir in care introduc caracterele pana la lmax
    int k = 0, lung = 0, spatii = 0; // k - indexul lui cuv1, lung - index care creste in paralel cu i
                                    // spatii - am nevoie pentru cazul(1)

    bool end = false; // il folosesc sa vad daca ajung la "."
    bool fin = false;
    int b = 0; // "lastindex"
    /* nota:
        acest for imi parcurge dinamic sirul si daca lung ajunge la lmax {

            cazul special(1): daca index ul pe care s-a oprit nu e spatiu imi copiaza in matrice
                DOAR pana la ultimul spatiu care este fix inainte de indexul unde s-a intrerupt
                ca sa nu imi "sparga" un cuvant in altele mai mici si sa distruga textul initial,
                iar cu cuvantul ramas de la spatiu spre dreapta se va atribui pe linia urmatoare
                iar linia urmatoare vine dupa cuvantul ramas, amandoua pe aceleasi linii

            (underscore reprezinta spatiu)
            ex: cuv1 = NU_MI_SE_PARE_FOARTE_(ultimul spatiu pana la intrerupere)_G
                pe linia 2 din text se copiaza pana la ultimul spatiu
                iar apoi pe linia 3 vine caracterul G

            cuv1 = REU_DE_REZOLVAT_IN_(ultimul spatiu pana la intrerupere)_TIM
            pe linia 3 dupa caracterul G vine REU_DE_REZOLVAT_IN_(cu tot cu spatiul de intrerupere)
            iar apoi pe linia 4 vin caracterele TIM

            cuv1 = PUL_ACORDAT.
            pe linia 4 imi pune cuv1 dupa TIM si cand ajunge la "." se opreste

            in aceste situatii am nevoie de un index care imi spune unde am ramas cu cuvantul pe care
            am picat cu limita

            spre ex: cuv1 = REU_DE_REZOLVAT_IN_(ultimul spatiu pana la intrerupere)_TIM
            aici se foloseste acel b de mai sus ("lastindex")
            incepe de la 0 si creste pana la strlen(TIM)
            apoi in urmatoarele iteratii atribui de la b incolo

            cazul normal(2): daca index ul pe care s-a oprit e spatiu imi copiaza integral pana la el
            ex: cuv1 = PROBLEMA_DE_LA_EXAMEN_
                pe linia 1 din text se atribuie cuv1
        }
    */
    //rezolvarea subpunctului a
    for(int i = 0; i < length; i++) // cu for parcug o singura data sirul str
    {
        lung++;
        cuv1[k++] = str[i]; // copiez caracter cu caracter
        if(str[i] == ' ')
        {
            spatii++; // am nevoie de spatiile din secventele pana la lmax de pe fiecare rand
        }
        if(lung == lmax)
        {
            if(str[i] != ' ') // cazul (1)
            {
                //iar eu dupa copiez de G incolo ca sa nu-mi suprascrie caractere din cuv1
                int nrspatii = 0;
                int j = 0;
                for(;; j++) // copiez cu for pana la ultimul spatiu
                            // care este fix inainte de limita
                {
                    if(nrspatii == spatii)
                    {
                        break; // se opreste la momentul potrivit
                    }
                    if(cuv1[j] == ' ')
                    {
                        nrspatii++; //tine cont de spatiile curente
                    }
                    text[rand][b++] = cuv1[j]; // atribui de la "lastindex"
                    cout << cuv1[j];
                }
                // ce este pana aici copiaza pana ultimul spatiu
                /* aici avem
                    ex: cuv1 = NU_MI_SE_PARE_FOARTE_(ultimul spatiu pana la intrerupere)_G
                    pe linia 2 din text se copiaza pana la ultimul spatiu
                    iar apoi pe linia 3 vine caracterul G
                */
                // de aici incolo il pune pe G pe linia urmatoare
                cout << endl;
                rand++; // am nevoie de linie sa pun caracterele ramase ale cuv pe care a picat lmax
                fin = true; // indicator pentru cazul (1) ca sa nu creez linii degeaba
                b = 0; // se reseteaza pt ca trec pe linie noua
                for(int h = j; h < lung; h++)
                {
                    if(cuv1[h] == '.') // daca ajung la "." am terminat
                    {
                        end = true;
                        break;
                    }
                    text[rand][b++] = cuv1[h]; // copiaza pe linie noua
                    cout << cuv1[h];
                }
            }
            else if(str[i] == ' ') // cazul (2)
            {
                print(k, cuv1);
                for(int j = 0; j < lung; j++)
                    text[rand][j] = cuv1[j];  //copiere integrala
                cout << endl;
            }
            lung = 0;
            spatii = 0;  // o luam de la capat din nou pana la lmax
            k = 0;
            if(!fin) // aici nu mai creez linii degeaba in functie de indicator
            {
                rand++;
                fin = false;
            }
        }
    }
    if(!end) // daca nu am ajuns la "." mi-au mai ramas caractere in cuv1 care nu se printeaza din
            // motive pe care nici eu nu le inteleg
    {
        int i = 0;
        for(;; i++)
        {
            if(cuv1[i] == '.')
                break; // cand ajung la "." stop
            text[rand][b++] = cuv1[i]; // copiez de la b incolo ce a mai ramas din cuv1
            cout << cuv1[i];
        }
        rand++; // am nevoie de inca o linie
        cout << "\n\n";
    }

    for(int i = 0; i < rand; i++) // afisez matricea si pun underscore pe post de indicator pentru spatiu
    {
        for(int j = 0; j < lmax; j++)
        {
            if(text[i][j] == ' ')
                cout << '_';
            else
                cout << text[i][j];
        }
        cout << endl;
    }

    // aici sunt rezolvare subpunctele b si c simultan
    int lungime = 1;
    int maxim = 1;

    cout << "\n";
    bool conect = false;
    for(int i = 0; i < rand; i++) //parcugere secventiala
    {
        for(int j = 0; j < lmax; j++)
        {
            if(text[i][j] == ' ') // daca gaseste un spatiu imi "sapa" pana in adancimea matricei pentru un rau
            {
                //resetez saparea
                bool next = false;
                int nivel = i;
                lungime = 1;
                do
                {
                    if(text[nivel][j] == text[nivel - 1][j - 1]
                       || text[nivel][j] == text[nivel - 1][j]
                       || text[nivel][j] == text[nivel - 1][j + 1]
                       || text[nivel][j] == text[nivel + 1][j - 1]
                       || text[nivel][j] == text[nivel + 1][j]
                       || text[nivel][j] == text[nivel + 1][j + 1]) // aici compara sus, jos si diagonalele
                    {
                        nivel++; // sapa mai jos (un fel de i++, dar fara sa modific i)
                        conect = true; // am gasit pt subpunctul b
                        lungime++; // aflu lungimea raului curent
                        next = true; // ma pot mai jos cu saparea
                    }
                    else
                    {
                        next = false; // nu pot sapa la infinit, trebuie sa se opreasca candva
                    }
                }
                while(next && nivel < rand - 1); // sapa cat timp gaseste conexiuni si daca ajungle la ultima linie se opreste
                maxim = max(maxim, lungime); // dupa fiecare sapare am nevoie de lungimea maxima
            }
        }
    }
    //pratic daca avem 1 singura conexiune, ea se considera rau deci subpunctele se afla in corelatie
    //afisari in functie de rezultate
    if(conect) {
        cout << "DA " << maxim << endl;
    }
    else
        cout << "NU" << endl;
    return 0;
}

//detalii de ignorat

//if(text[i][j] == text[i - 1][j - 1] || text[i][j] == text[i - 1][j] || text[i][j] == text[i - 1][j + 1] || text[i][j] == text[i + 1][j - 1] || text[i][j] == text[i + 1][j] || text[i][j] == text[i + 1][j + 1])
//                    conect = true;
//
//
//if(text[i][j] == ' ')
//{
//    if(i == 0)
//    {
//        if(j == lmax - 1)
//        {
//            if(text[i][j] == text[i + 1][j] || text[i][j] == text[i + 1][j - 1])
//                conect = true;
//        }
//        else if(text[i][j] == text[i + 1][j - 1] || text[i][j] == text[i + 1][j] || text[i][j] == text[i + 1][j + 1])
//            conect = true;
//    }
//    else if(i == rand - 1)
//    {
//        if(j == lmax - 1)
//        {
//            if(text[i][j] == text[i][j - 1] || text[i][j] == text[i - 1][j])
//                conect = true;
//        }
//        else if(text[i][j] == text[i - 1][j] || text[i][j] == text[i - 1][j + 1] || text[i][j] == text[i - 1][j - 1])
//            conect = true;
//    }
//    else if(j = lmax - 1)
//    {
//        if(text[i][j] == text[i - 1][j] || text[i][j] == text[i - 1][j - 1] || text[i][j] == text[i + 1][j - 1] || text[i][j] == text[i + 1][j])
//            conect = true;
//    }
//    else
//    {
//        if(text[i][j] == text[i - 1][j - 1] || text[i][j] == text[i - 1][j] || text[i][j] == text[i + 1][j + 1] || text[i][j] == text[i + 1][j - 1] || text[i][j] == text[i + 1][j] || text[i][j] == text[i + 1][j + 1])
//            conect = true;
//    }
//}
//




