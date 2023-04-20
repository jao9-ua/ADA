//Juan Andrés Orocondo Álvarez 20993208G
#include <iostream>
#include <math.h>

using namespace std;

unsigned long cont1=0;
unsigned long cont2=0;
unsigned long cont3=0;

// complejidad de O(n)
unsigned long pow2_1(unsigned long d)
{
    unsigned long sol = 1;
    for (unsigned long i = 0; i < d; i++)
    {
        cont1++;
        sol = sol * 2;
    }
    return sol;
}

//Complejidad de O(logn)
unsigned long pow2_2(unsigned d)
{
    cont2++;
    if (d == 0)
    {
        return 1;
    }
    int mitad = pow2_2(d / 2);
    if (d % 2 == 0)
    {
        return mitad * mitad;
    }
    else
    {
        return 2 * mitad * mitad;
    }
}

//Complejidad de O(2^n)
unsigned long pow2_3(unsigned d)
{
    unsigned long sol = 0;
    cont3++;
    if (d ==0)
    {
        return 1;
    }
    else if (d == 1)
    {
        return 2;
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            sol+= (pow2_3(d-1));
        }
        
    }
    return sol;
}

int main()
{
    for(unsigned long i=0; i<25;i++)
    {
        cont1=cont2=cont3=0;
        
        if(pow2_1(i) !=pow(2,i)){
            cerr << "Error calculando" << endl;
        }
        else
        {
            cout << cont1 << "\t";
        }
        if(pow2_2(i) !=pow(2,i)){
            cerr << "Error calculando" << endl;
        }
        else
        {
            cout << cont2 << "\t";
        }
        if(pow2_3(i) !=pow(2,i)){
            cerr << "Error calculando" << endl;
        }
        else
        {
            cout << cont3 << endl;
        }

    }
    return 0;
}