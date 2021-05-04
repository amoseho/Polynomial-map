#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string polynomial;
    string polynomial2;
    ifstream infile("input.txt");
    ofstream outfile;
    outfile.open ("output.txt");
    int x = 10;

    while(getline(infile, polynomial))
    {
        getline(infile, polynomial2);
        int coeff, power;
        istringstream p1(polynomial);
        istringstream p2(polynomial2);
        map<int,int, greater<int> > poly1;
        map<int,int, greater<int> > poly2;
        map<int,int, greater<int> > add;
        map<int,int, greater<int> > sub;
        map<int,int, greater<int> > mul;
        outfile << "first polynomial" << endl;
        while (p1 >> coeff >> power)
        {
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            else
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
            if(poly1.count(power))
            {
                poly1[power] += coeff;
            }
            else
            {
                poly1.insert(make_pair(power,coeff));
            }
        }

        outfile << endl;
        map<int,int>::iterator poly1_iterator;
        for(poly1_iterator = poly1.begin(); poly1_iterator != poly1.end(); poly1_iterator++)
        {
            coeff = poly1_iterator->second;
            power = poly1_iterator->first;
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            if(coeff < 0)
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
        }
        outfile << endl;
        outfile << "second polynomial";
        outfile << endl;
        while (p2 >> coeff >> power)
        {
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            else
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
            if(poly2.count(power))
            {
                poly2[power] += coeff;
            }
            else
            {
                poly2.insert(make_pair(power,coeff));
            }
        }
        outfile << endl;
        map<int,int>::iterator poly2_iterator;
        for(poly2_iterator = poly2.begin(); poly2_iterator != poly2.end(); poly2_iterator++)
        {
            coeff = poly2_iterator->second;
            power = poly2_iterator->first;
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            if(coeff < 0)
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
        }
        outfile << endl;
        outfile << "addition";
        outfile << endl;
        add = poly1;
        map<int,int>::iterator it;
        for(it = poly2.begin(); it != poly2.end(); it++)
        {
            add[it->first] += it->second;
        }
        sub = poly1;
        for(it = poly2.begin(); it != poly2.end(); it++)
        {
            sub[it->first] -= it->second;
        }
        map<int,int>::iterator add_iterator;
        for(add_iterator = add.begin(); add_iterator != add.end(); add_iterator++)
        {
            coeff = add_iterator->second;
            power = add_iterator->first;
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            if(coeff < 0)
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
        }
        outfile << endl;
        outfile << "subtraction";
        outfile << endl;
        map<int,int>::iterator sub_iterator;
        for(sub_iterator = sub.begin(); sub_iterator != sub.end(); sub_iterator++)
        {
            coeff = sub_iterator->second;
            power = sub_iterator->first;
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            if(coeff < 0)
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
        }
        outfile << endl;
        outfile << "multiplication";
        outfile << endl;
        map<int,int, greater<int> >::iterator mul1;
        map<int,int, greater<int> >::iterator mul2;

        for(mul1 = poly1.begin(); mul1 != poly1.end(); mul1++) {
            for(mul2 = poly2.begin(); mul2 != poly2.end(); mul2++) {

                power = mul1->first + mul2->first;
                coeff = mul1->second * mul2->second;

                if(mul.count(power))
                {
                    mul[power] += coeff;
                }
                else
                {
                    mul.insert(make_pair(power,coeff));
                }
            }
        }
        map<int,int>::iterator mul_iterator;
        for(mul_iterator = mul.begin(); mul_iterator != mul.end(); mul_iterator++)
        {
            coeff = mul_iterator->second;
            power = mul_iterator->first;
            if(coeff > 0)
            {
                if(power == 1)
                {
                    outfile << "+" << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << "+" << coeff;
                }
                else
                {
                    outfile << "+" << coeff << "x^" << power;
                }
            }
            if(coeff < 0)
            {
                if(power == 1)
                {
                    outfile << coeff << "x";
                }
                else if(power == 0)
                {
                    outfile << coeff;
                }
                else
                {
                    outfile << coeff << "x^" << power;
                }
            }
        }
        outfile << endl << endl;
        poly1.clear();
        poly2.clear();
        add.clear();
        sub.clear();
        mul.clear();
    }
    outfile.close();
    return 0;
}
