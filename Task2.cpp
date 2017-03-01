#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int n[1000], m[1000];
int sum[1000]={0}, cnt=0;
int diff[1000]={0}; 
int mult[1000]={0};
int empty[1000]={0};


class Number
{ 	
	public:
	void addition(int n[], int, int);
	void difference(int, int n[], int, int, int m[], int, int);
	void multiplication(int n[], int, int m[], int, int);
	void division(int,int);
	int interconvert(int, int, int); 
	int base;

} ;

Number object;


class Run
{
public:
	void menu(void);
};
Run execute;

void Run::menu(void)
{
	int N;
	
	
    cout << "\nEnter base: \n";
    cout << "1. 10 for decimal \n2. 2 for binary\n";
    cout << "3. 8 for octal \n";

    cin >> N;

    switch(N){
  	
  	case 10: object.base = 10;
  	break;

	case 2:	object.base = 2;
	break;

  	case 8: object.base = 8;
  	break;

  	default : cout << "new base mode" << endl;
 				object.base = N;
 				break;
 

	};


};




void Number::addition(int n[], int i, int base)
{
	int k;
	
	for (k=0; k<i && k<cnt ; k++)
	{
		if(sum[k] + n[k] < base)
		{
			sum[k] = sum[k] + n[k];
		}
		else
		{
			sum[k] = sum[k] + n[k] - base;
			sum[k+1] = sum[k+1] + 1;
		}
		cnt++;
	}


	while(i-cnt>0)
	{
		sum[cnt] = sum[cnt] +  n[cnt];
		cnt++;
	}

	if(sum[cnt]!=0) cnt++;

}


void Number::difference(int a, int n[], int i, int b, int m[], int j, int base)
{
	int k;
	
	
	if(a>=b) 
	{
		for(k=0; k<i && k<j; k++)
		{
			if(n[k] >= m[k])
			diff[k] = diff[k] + n[k] - m[k];
			else
			{
				diff[k] = diff[k] + n[k] + base - m[k];
				diff[k+1] = diff[k+1] - 1;
			}
		}

		while(j-k>0)
		{
			diff[k] = diff[k] +  m[k];
			k++;
		}

		while(i-k>0)
		{
			diff[k] = diff[k] +  n[k];
			k++;
		}

		if(diff[k]!=0) k++;
		cnt = k;	
	}

	else
	{
		for(k=0; k<i && k<j; k++)
		{
			if(m[k] >= n[k])
			diff[k] = diff[k] + m[k] - n[k];
			else
			{
				diff[k] = diff[k] + m[k] + base - n[k];
				diff[k+1] = diff[k+1] - 1;
			}
		}

		while(j-k>0)
		{
			diff[k] = diff[k] +  m[k];
			k++;
		}

		while(i-k>0)
		{
			diff[k] = diff[k] +  n[k];
			k++;
		}

		if(diff[k]!=0) k++;
		cnt = k;

	}

}

void Number::multiplication(int n[], int i, int m[], int j, int base)
{

	int k, t, temp, ans[1000][1000], CNT, l;

	for(l=1; l<1000; l++)
	{
		for(int m=0; m<l; m++)
		{
			ans[l][m] = 0;
		}
	}

	for(k=0; k<i; k++)
	{
		for (t=0; t<j; t++)
		{
			if(m[t] * n[k] < base)
			{
				ans[k][t+k] = ans[k][t+k] + m[t] * n[k];

			}
			else
			{
				temp = m[t] * n[k];
				ans[k][t+k] = ans[k][t+k] + temp % 10;
				ans[k][t+k+1] = ans[k][t+k+1] + (temp/10);
			}
				
		}

		

		if((ans[k][t+k])!=0) t++;
		CNT = t+k;


	}



	for(l=0; l<i; l++)
	{
		Number::addition(ans[l], CNT, base);
	}

	for(i=0; i<cnt; i++)
	{
		mult[i] = sum[i];
		sum [i] = 0;
	}

	for(l=0; l<1000; l++)
	{
		for(int m=0; m<1000; m++)
		{
			ans[l][m] = 0;
		}
	}

}

int Number::interconvert(int n1, int base1, int base2)
{
	int i, n2=0, t=0, a[1000], b[1000], answer=0;
	for(i=0; n1!=0; i++)
	{
		a[i] = n1%10;
		n1=n1/10;

		n2 = n2 + pow(base1,i) * a[i];
	}

	for(i=0; n2!=0; i++)
	{	
		b[i] = n2 % (base2);
		n2 = n2/(base2);
		t++;
	}

	for(i=0; i<t; i++)
	{
		answer = answer + pow(10,i) * b[i];
	}

	return answer; 
}




int main()
{
	int i, j, t, a, b, c, d, e, x[1000], y[1000], cnt1=0,cnt2=0,cnt3=0, ans;
	char ch;
	label:
	while(1){

		ans = 0;

		for(int l=0; l<1000; l++)
		{
			sum[l] = 0;
			diff[l] = 0;
			mult[l] = 0;
			x[l] = 0;
			y[l] = 0;
		}
		
	execute.menu();

	cout << "Enter choice of operation: \n";
	cout << "1. + for addition \n2. - for difference\n";
	cout << "3. * for multiplication \n4. # for interconversion\n";

	cin >> ch;

	switch(ch){

	case '+': 
		
		cout << "Enter A: ";	
		cin >> a;
		d = a;
		
		for(i=0; a!=0; i++)
		{
			x[i] = a%10;
			if(x[i]>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			a = a/10;
			cnt1++;
		}

		cout << "Enter B: ";
		cin >> b;
		e = b;

		for(j=0; b!=0; j++)
		{
			y[j] = b%10;
			if(y[j]>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			b = b/10;
			cnt2++;
		}

		object.addition(x, cnt1, object.base);
		object.addition(y, cnt2, object.base);

		for(i=0; i<cnt; i++)
		{
			ans = ans + pow(10,i) * sum[i];
		}

		cout << ans <<endl;
		ans = 0;
		break;


	case '-':
		
		cout << "Enter A: ";
		cin >> a;
		d = a;
		
		for(i=0; a!=0; i++)
		{
			x[i] = a%10;
			if(x[i]>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			a = a/10;
			cnt1++;
		}

		cout << "Enter B: ";
		cin >> b;
		e = b;

		for(j=0; b!=0; j++)
		{
			y[j] = b%10;
			if(y[j]>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			b = b/10;
			cnt2++;
		}

		object.difference(d, x, cnt1, e, y, cnt2, object.base);

		for(i=0; i<cnt; i++)
		{
			ans = ans + pow(10,i) * diff[i];
		}

		cout << ans <<endl;
		ans = 0;
		break;

	case '*': 
		
		cout << "Enter A: ";	
		cin >> a;
		d = a;
		
		for(i=0; a!=0; i++)
		{
			x[i] = a%10;
			if(x[i]>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			a = a/10;
			cnt1++;
		}

		cout << "Enter B: ";
		cin >> b;
		e = b;

		for(j=0; b!=0; j++)
		{
			y[j] = b%10;
			if(y[j]>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			b = b/10;
			cnt2++;
		}

		object.multiplication(x, cnt1, y, cnt2, object.base);

		for(i=0; i<cnt; i++)
		{
			ans = ans + pow(10,i) * mult[i];
		}

		cout << ans <<endl;
		ans =0;
		break;

	case '#':
		
		cout << "Enter A: ";	
		cin >> a;
		d = a;
		while (a!=0)
		{
			if(a%10>=object.base)
			{
				cout << "invalid input";
				goto label;
			}
			a = a/10;

		}

		cout << "Enter base of system to convert to: ";
		cin >> c;

		e = object.interconvert(d, object.base, c);

		cout << endl << e;
		break; 
	default : cout << "invalid operation";
	goto label;

	};

	cout << "Wanna continue? [Y/N]" << endl;
	cin >> ch;
	if(ch == 'N' | ch == 'n')
	{
		exit(0);
	}
	
	}
 
}
