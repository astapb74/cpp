// chislo13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char format[] = "%s %s\n";
char hello[] = "Hello";
char world[] = "world";

class Controle {
private:
    bool eq(string ch)
    {
        string v1("0123456789ABC");

        int sum1 = 0;
        string tmp, tmp2;
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= 12; j++) {
                tmp = ch[i];
                tmp2 = v1[j];
                //cout << tmp << " = " << j << endl;
                if (tmp == tmp2) {
                    sum1 += j;
                }
            }
        }
        int dSum1 = 0;
        for (int i = 6; i <= 12; i++) {
            for (int j = 0; j <= 12; j++) {
                tmp = ch[i];
                tmp2 = v1[j];

                if (tmp == tmp2) {
                    //cout << tmp << " = " << j << endl;
                    dSum1 += j;
                }
            }
        }

        return sum1 == dSum1;
    }
public:
    void showChislo() {
        string chislo1("0055237050A00");
        string chislo2("000001000001");
        string chislo3("ABA98859978C0");
        string chislo4("6789110551234");
        string chislo5("0000007000000");

        cout << chislo1 << (this->eq(chislo1) ? " beautiful" : " ugly") << endl;
        cout << chislo2 << (this->eq(chislo2) ? " beautiful" : " ugly") << endl;
        cout << chislo2 << (this->eq(chislo3) ? " beautiful" : " ugly") << endl;
        cout << chislo2 << (this->eq(chislo4) ? " beautiful" : " ugly") << endl;
        cout << chislo2 << (this->eq(chislo5) ? " beautiful" : " ugly") << endl;
    };
    int power2(int num, int power)
    {
        __asm
        {
            mov eax, num; Get first argument
            mov ecx, power; Get second argument
            shl eax, cl; EAX = EAX * (2 to the power of CL)
        }
        // Return with result in EAX
    };
    int showAsm(void)
    {
        __asm
        {
            mov  eax, offset world
            push eax
            mov  eax, offset hello
            push eax
            mov  eax, offset format
            push eax
            call printf
            //clean up the stack so that main can exit cleanly
            //use the unused register ebx to do the cleanup
            pop  ebx
            pop  ebx
            pop  ebx
        }

    };
};

int main()
{
    Controle c;
    int a;

    cout << "Please enter: 1 - from hex 13 number;" << endl;
    cout << "Please enter: 2 - from assembler calc;" << endl;
    cout << "Please enter: 3 - from assembler text;" << endl;
    cin >> a;
    switch (a)
    {
        case 1:
            c.showChislo();
            break;
        case 2:
            cout << "294859484x3932847237=" << c.power2(294859484, 3932847237) << endl;
            break;
        default:
            c.showAsm();
            break;
    }
    
}
