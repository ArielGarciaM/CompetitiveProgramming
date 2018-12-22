#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c, d, score;
    cin >> a >> b >> c >> d;
    score = 0.2*a + 0.3*b + 0.4*c + 0.1*d;
    cout << fixed << setprecision(1);
    cout << "Media: " << score << endl;
    if(score >= 7.0)
        cout << "Aluno aprovado.\n";
    else if(score < 5.0)
        cout << "Aluno reprovado.\n";
    else
    {
        cout << "Aluno em exame.\n";
        double exam;
        cin >> exam;
        cout << "Nota do exame: " << exam << endl;
        if(exam >= 5.0)
            cout << "Aluno aprovado.\n";
        else
            cout << "Aluno reprovado.\n";
        cout << "Media final: " << (score + exam)*0.5 << endl;
    }
}