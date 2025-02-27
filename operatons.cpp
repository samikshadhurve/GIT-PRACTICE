#include <iostream>
using namespace std;

typedef struct poly {
    int expo;
    int coeff;
} poly;

class poly_op {
private:
    poly p[10]; // Limiting to 10 terms for simplicity
    int terms;

public:
    poly_op() {
        terms = 0;
    }

    void input() {
        cout << "Enter no of terms:";
        cin >> terms;
        for (int i = 0; i < terms; i++) {
            cout << "\nEnter coefficient and exponent in descending order:";
            cin >> p[i].coeff;
            cin >> p[i].expo;
        }
        cout << "\n";
    }

    void display() {
        for (int i = 0; i < terms; i++) {
            cout << p[i].coeff << "X^" << p[i].expo;
            if (i != terms - 1) {
                cout << "+";
            }
        }
        cout << endl;
    }

    void add_poly(poly_op a, poly_op b) {
        int i = 0, j = 0, k = 0;

        while (i < a.terms && j < b.terms) {
            if (a.p[i].expo == b.p[j].expo) {
                p[k].coeff = a.p[i].coeff + b.p[j].coeff;
                p[k].expo = a.p[i].expo;
                i++, j++, k++;
            } else if (a.p[i].expo > b.p[j].expo) {
                p[k].coeff = a.p[i].coeff;
                p[k].expo = a.p[i].expo;
                i++, k++;
            } else {
                p[k].coeff = b.p[j].coeff;
                p[k].expo = b.p[j].expo;
                j++, k++;
            }
        }
        while (i < a.terms) {
            p[k].coeff = a.p[i].coeff;
            p[k].expo = a.p[i].expo;
            i++, k++;
        }
        while (j < b.terms) {
            p[k].coeff = b.p[j].coeff;
            p[k].expo = b.p[j].expo;
            j++, k++;
        }
        terms = k;
    }

    void evaluate(int x) {
        int sum = 0;
        for (int k = 0; k < terms; k++) {
            int prod = 1;
            for (int i = 0; i < p[k].expo; i++) {
                prod = prod * x;
            }
            sum = sum + (p[k].coeff * prod);
        }
        cout << "The value after Evaluation is: " << sum << endl;
    }

    void multiply(poly_op a, poly_op b, poly_op& result) {
        int k = 0;
        for (int i = 0; i < a.terms; i++) {
            for (int j = 0; j < b.terms; j++) {
                int tempcoeff = a.p[i].coeff * b.p[j].coeff;
                int tempexpo = a.p[i].expo + b.p[j].expo;

                int temp = 0;
                while (temp < k && result.p[temp].expo > tempexpo) {
                    temp++;
                }
                if (temp < k && result.p[temp].expo == tempexpo) {
                    result.p[temp].coeff += tempcoeff;
                } else {
                    for (int x = k; x > temp; x--) {
                        result.p[x] = result.p[x - 1];
                    }
                    result.p[temp].coeff = tempcoeff;
                    result.p[temp].expo = tempexpo;
                    k++;
                }
            }
        }
        result.terms = k;
    }
};

int main() {
    poly_op a;
    poly_op b;
    poly_op c;
    poly_op result;
    int cas;
    int x;
    
    cout << "Please enter your choice:" << endl;
    cout << "1 - Polynomial addition" << endl;
    cout << "2 - Polynomial evaluation" << endl;
    cout << "3 - Polynomial multiplication" << endl;
    cin >> cas;
    
    switch (cas) {
        case 1:
            cout << "Polynomial A:" << endl;
            a.input();
            cout << "Polynomial B:" << endl;
            b.input();
            c.add_poly(a, b);
            cout << "The sum of given polynomials is: ";
            c.display();
            break;
            
        case 2:
            cout << "Enter the value of x: ";
            cin >> x;
            cout << "Polynomial A:" << endl;
            a.input();
            cout << "Value of Polynomial A at x = " << x << ": ";
            a.evaluate(x);
            break;
            
        case 3:
            cout << "Polynomial A:" << endl;
            a.input();
            cout << "Polynomial B:" << endl;
            b.input();
            result.multiply(a, b, c);
            cout << "The product of given polynomials is: ";
            c.display();
            break;
    }

    return 0;
}
