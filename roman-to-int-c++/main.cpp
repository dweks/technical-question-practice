#include <string>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int I_COUNT = 0;
int V_COUNT = 0;
int X_COUNT = 0;
int L_COUNT = 0;
int C_COUNT = 0;
int D_COUNT = 0;
int M_COUNT = 0;

int romanToInt(string);
void increment(const char, const char);
void validate(const char, const char);
int getValue(const char, const char, const char);
void resetCounts();

int main()
{
    string s;
    do
    {
        cout << "Enter roman numeral > ";
        cin >> s; cin.ignore();

        try {
            cout << "Converting " << s << " to integer:" << endl << romanToInt(s) << endl;
        }
        catch (const int e) {
            cerr << "String length out of range [1, 15]: " << e << endl;
        }
        catch (const char * e) {
            cerr << "\nFailure: " << e << endl;
        }
        catch (const char e) {
            cerr << "\nInvalid numeral: " << e << endl;
        }

        resetCounts();

    } while (s != "q" && s != "Q");

    return 0;
}

int romanToInt(string s) {
    size_t len{s.length()};
    int sum{0};

    if (len < 1 || len > 15)
        throw len;

    for (int i{0}; i < len; ++i)
    {
        char n{'\0'};
        char p{'\0'};
        char c = s[i];

        if(i < len - 1)
            n = s[i + 1];
        if(i > 0)
            p = s[i - 1];

        validate(c, n);
        increment(c, n);
        int hold = getValue(c, p, n);
        if(hold > 0) {
            sum += hold;
            if (i < len - 1)
                cout << " + ";
            else
                cout << " = ";
        }
    }
    return sum;
}

int getValue(const char c, const char p, const char n) {
    int val{0};
    string numeral;

    if (c == 'M') {
        if(p == 'C') {
            val = M - C;
            numeral = "CM";
        } else {
            val = M;
            numeral = "M";
        }
    } else if (c == 'D'){
        if(p == 'C'){
            val = D - C;
            numeral = "CD";
        } else {
            val = D;
            numeral = "D";
        }
    } else if (c == 'C'){
        if (n == 'D' || n == 'M')
            return 0;

        if(p == 'X') {
            val = C - X;
            numeral = "XC";
        } else {
            val = C;
            numeral = "C";
        }
    } else if (c == 'L'){
        if(p == 'X') {
            val = L - X;
            numeral = "XL";
        } else {
            val = L;
            numeral = "L";
        }
    } else if (c == 'X'){
        if (n == 'L' || n == 'C')
            return 0;

        if(p == 'I') {
            val = X - I;
            numeral = "IX";
        } else {
            val = X;
            numeral = "X";
        }
    } else if (c == 'V'){
        if(p == 'I') {
            val = V - I;
            numeral = "IV";
        } else {
            val = V;
            numeral = "V";
        }
    } else if (c == 'I') {
        if(n == 'V' || n == 'X')
            return 0;
        val = I;
        numeral = "I";
    }

    cout << numeral << " (" << val << ")";
    return val;
}

void increment(const char c, const char n) {
    if (c == 'M' && n == 'M')
        ++M_COUNT;

    else if (c == 'D')
        ++D_COUNT;

    else if (c == 'C' && n == 'C')
        ++C_COUNT;

    else if (c == 'L')
        ++L_COUNT;

    else if (c == 'X' && n == 'X')
        ++X_COUNT;

    else if (c == 'V')
        ++V_COUNT;

    else if (c == 'I' && n == 'I')
        ++I_COUNT;
}

void validate(const char c, const char n) {
    if (c == 'M') {
        if(M_COUNT > 2) throw "Cannot have more than three consecutive M's";
    } else if (c == 'D'){
        if(D_COUNT > 1) throw "Cannot have multiple D's";
        if(n == 'M') throw "M cannot come after D";
        if(n == 'D') throw "M cannot come after D";
    } else if (c == 'C') {
        if(C_COUNT > 2) throw "Cannot have more than three consecutive C's";
    } else if (c == 'L'){
        if(L_COUNT > 1) throw "Cannot have multiple L's";
        if(n == 'M') throw "M cannot come after L";
        if(n == 'D') throw "D cannot come after L";
        if(n == 'C') throw "C cannot come after L";
    } else if (c == 'X'){
        if(X_COUNT > 2) throw "Cannot have more than three consecutive X's";
        if(n == 'M') throw "M cannot come after X";
        if(n == 'D') throw "D cannot come after X";
    } else if (c == 'V'){
        if(V_COUNT > 1) throw "Cannot have multiple V's";
        if(n == 'M') throw "M cannot come after V";
        if(n == 'D') throw "D cannot come after V";
        if(n == 'C') throw "C cannot come after V";
        if(n == 'L') throw "L cannot come after V";
        if(n == 'X') throw "X cannot come after V";
    } else if (c == 'I'){
        if(I_COUNT > 2) throw "Cannot have more than three consecutive I's";
        if(n == 'M') throw "M cannot come after I";
        if(n == 'D') throw "D cannot come after I";
        if(n == 'C') throw "C cannot come after I";
        if(n == 'L') throw "L cannot come after I";
    } else {
        throw c;
    }
}

void resetCounts() {
    I_COUNT = 0;
    V_COUNT = 0;
    X_COUNT = 0;
    L_COUNT = 0;
    C_COUNT = 0;
    D_COUNT = 0;
    M_COUNT = 0;
}