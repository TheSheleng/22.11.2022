#include <Windows.h>
#include <iostream>
#include <exception>
#include <conio.h>

using namespace std;

class Calcul
{
    Calcul()
    {
        hInstLib = LoadLibrary(TEXT("MyLib.dll"));
        if (hInstLib == NULL) throw exception("Can`t load library MyLib.dll");

        Sum = (lpFAct)GetProcAddress(hInstLib, "Sum");
        Min = (lpFAct)GetProcAddress(hInstLib, "Min");
        Mult = (lpFAct)GetProcAddress(hInstLib, "Mult");
        Div = (lpFAct)GetProcAddress(hInstLib, "Div");
        if (Sum == NULL || Min == NULL || Mult == NULL || Div == NULL)
            throw exception("Can`t load function");
    };

    ~Calcul()
    {
        FreeLibrary(hInstLib);
    }

    Calcul(const Calcul&) = delete;
    Calcul& operator= (const Calcul&) = delete;

    HINSTANCE hInstLib;

    typedef float (*lpFAct) (float, float);
    lpFAct Sum, Min, Mult, Div;

public:
    static enum ACTIONS
    {
        SUM,
        MIN,
        MULT,
        DIV,
    };
    static float Culc(ACTIONS act, float a, float b)
    {
        static Calcul Singl;
        float answ = 0;

        switch (act)
        {
        case SUM: answ = Singl.Sum(a, b); break;
        case MIN: answ = Singl.Min(a, b); break;
        case MULT: answ = Singl.Mult(a, b); break;
        case DIV:
            try { answ = Singl.Div(a, b); break; }
            catch (const char* ex) { throw exception(ex); }
        }

        return answ;
    }
};


int main()
{
    float a, b;
    cout << "Enter first num: ";
    cin >> a;
    cout << "Enter seccond num: ";
    cin >> b;
    cout << endl;

    cout << "Chose action: " << endl
        << "\t1. Sum" << endl
        << "\t2. Min" << endl
        << "\t3. Mult" << endl
        << "\t4. Div" << endl;
    try
    {
        switch (_getch())
        {
        case '1': cout << Calcul::Culc(Calcul::SUM, a, b); break;
        case '2': cout << Calcul::Culc(Calcul::MIN, a, b); break;
        case '3': cout << Calcul::Culc(Calcul::MULT, a, b); break;
        case '4': cout << Calcul::Culc(Calcul::DIV, a, b); break;
        }
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what();
    }
}
