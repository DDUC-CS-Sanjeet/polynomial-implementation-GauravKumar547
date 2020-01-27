#include<iostream>
using namespace std;

class Polynomial
{
    private:
        int *p;
        int degree;
    public:
    	Polynomial()
    	{
    		p=0;
    		degree=0;
		}
        Polynomial(int deg )
        { 
            p = new int[deg+1];
            this->degree = deg;
        }
        void storePolynomial()
        {
            for(int i = 0; i <= degree; ++i)
            {
                cout << "Enter coefficient for x^" << i << ": ";
                cin >> p[i];
            }
        }
        void display()
        {
            for(int i = degree; i >=0; i--)
            {
                
                if(i==0)
                {
                    cout << p[i] << "x^" << i<<" ";
				}
				else
				{
					cout << p[i] << "x^" << i<<" + ";
				}
            }
            cout << "\n";
        }
        Polynomial operator +(Polynomial& poly)
        {
            Polynomial new_p;
            int max_degree = poly.degree > degree ? poly.degree : degree;
            new_p.degree = max_degree;
            new_p.p = new int[max_degree+1]{0};
            for(int i = 0; i <= max_degree; ++i)
            {
                if(i <= degree) new_p.p[i] += p[i];
                if(i <= poly.degree) new_p.p[i] += poly.p[i];
            }
            return new_p;
        }
        Polynomial operator -(Polynomial& poly)
        {
            Polynomial new_p;
            int max_degree = poly.degree > degree ? poly.degree : degree;
            new_p.degree = max_degree;
            new_p.p = new int[max_degree+1]{0};
            for(int i = 0; i <= max_degree; ++i)
            {
                if(i <= degree) new_p.p[i] += p[i];
                if(i <= poly.degree) new_p.p[i] -= poly.p[i];
            }
            return new_p;
        }
        ~Polynomial()
        {
        	cout<<"\nThe memory for polynomial is deallocated\n";
        }
};

int main()
{
	int degFirst , degSecond;
	cout<<" Enter the degree first :  ";
	cin>>degFirst;
	cout<<" Enter the degree second : ";
	cin>>degSecond;
    Polynomial firstPolynomial(degFirst);
    firstPolynomial.storePolynomial();
    firstPolynomial.display();
    Polynomial secondPolynomial(degSecond);
    secondPolynomial.storePolynomial();
    secondPolynomial.display();
    Polynomial thirdPolynomial = firstPolynomial + secondPolynomial;
    cout<<"Adding first and second Polynomial::::   Results into::::    ";
    thirdPolynomial.display();
    Polynomial fourthPolynomial = firstPolynomial - secondPolynomial;
    cout<<"Subracting second Polynomial from first:::  Results into:::   ";
    fourthPolynomial.display();
    return 0;
}
