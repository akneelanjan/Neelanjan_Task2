#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n[1000], m[1000], T=0, conv[1000]={0};
int sum[1000]={0}, cnt=0;
int diff[1000]={0}; 
int mult[1000]={0};
int Division[1000]={0};
int empty[1000]={0};


class Number
{ 	
	public:
	void addition(int n[], int);
	void difference(int, int n[], int, int, int m[], int);
	void multiplication(int n[], int, int m[], int);
	void division(int n[], int, int m[], int);
	void interconvert(int n[], int, int); 
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
    cout << "3. 8 for octal \n4. 16 for hexadecimal\n";

    cin >> N;

    switch(N){
  	
  	case 10: object.base = 10;
  	break;

	case 2:	object.base = 2;
	break;

  	case 8: object.base = 8;
  	break;

  	case 16: object.base = 16;
  	break;

  	default : cout << "new base mode" << endl;
 				object.base = N;
 				break;
 

	};


}




void Number::addition(int n[], int i)
{
	int k;
	
	for (k=0; k<i && k<cnt ; k++)
	{
		if(sum[k] + n[k] < object.base)
		{
			sum[k] = sum[k] + n[k];
		}
		else
		{
			sum[k] = sum[k] + n[k] - object.base;
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


void Number::difference(int a, int n[], int i, int b, int m[], int j)
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
				diff[k] = diff[k] + n[k] + object.base - m[k];
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
				diff[k] = diff[k] + m[k] + object.base - n[k];
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

void Number::multiplication(int n[], int i, int m[], int j)
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
			if(m[t] * n[k] < object.base)
			{
				ans[k][t+k] = ans[k][t+k] + m[t] * n[k];

			}
			else
			{
				temp = m[t] * n[k];
				ans[k][t+k] = ans[k][t+k] + temp % (object.base);
				ans[k][t+k+1] = ans[k][t+k+1] + (temp/(object.base));
			}
				
		}

		

		if((ans[k][t+k])!=0) t++;
		CNT = t+k;


	}



	for(l=0; l<i; l++)
	{
		Number::addition(ans[l], CNT);
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

void Number::interconvert(int n[], int i, int base2)
{
	int j, n2=0;
	for(j=0; j<i; j++)
	{
		n2 = n2 + pow(object.base,j) * n[j];
	} 

	for(j=0; n2!=0; j++)
	{	
		conv[j] = n2 % (base2);
		n2 = n2/(base2);
		T++;
	}

	
}

void Number::division(int n[], int i, int m[], int j)
{
	int z, n1=0, m1=0, answer=0;
	for(z=0; z<i; z++)
	{
		n1 = n1 + pow(object.base,z) * n[z];
	} 

	for(z=0; z<i; z++)
	{
		m1 = m1 + pow(object.base,z) * m[z];
	} 

	if(m1==0)
	{
		cout << "Division by zero" << endl;
		exit(0);
	}


	else
	{
		answer = n1/m1;
		for(z=0; answer!=0; z++)
		{
			Division[z] = answer % (object.base);
			answer = answer/(object.base);
			T++;
		} 	
	}
	


}




int main()
{
	int i, j, a, b, c, d, e, f, x[1000], y[1000], cnt1=0,cnt2=0,cnt3=0, ans, len, temp, answer;
	char ch, A[1000], B[1000], ANS[1000];
	label:
	while(1){

		ans = 0, answer = 0;

		for(int l=0; l<1000; l++)
		{
		
			Division[l] = 0;			
			sum[l] = 0;
			diff[l] = 0;
			mult[l] = 0;
			conv[l] = 0;
			x[l] = 0;
			y[l] = 0;
		}
		
	execute.menu();

	cout << "Enter choice of operation: \n";
	cout << "1. + for addition \n2. - for difference\n";
	cout << "3. * for multiplication \n4. / for division \n5. # for interconversion\n";

	cin >> ch;

	if(object.base == 16)
	{
		switch(ch){

		case '+': 
			cout << "Enter A: ";
			cin >> A;
			len = strlen(A);
			
			for(i=0; i<len; i++)
			{
				switch(A[len-i-1]){
					case '0': x[i] = 0;
					break;
					case '1': x[i] = 1;
					break;
					case '2': x[i] = 2;
					break;
					case '3': x[i] = 3;
					break;
					case '4': x[i] = 4;
					break;
					case '5': x[i] = 5;
					break;
					case '6': x[i] = 6;
					break;
					case '7': x[i] = 7;
					break;
					case '8': x[i] = 8;
					break;
					case '9': x[i] = 9;
					break;
					case 'A': x[i] = 10;
					break;
					case 'B': x[i] = 11;
					break;
					case 'C': x[i] = 12;
					break;
					case 'D': x[i] = 13;
					break;
					case 'E': x[i] = 14;
					break;
					case 'F': x[i] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				};
				cnt1++;
			}

			cout << "Enter B: ";
			cin >> B;
			len = strlen(B);
			
			for(j=0; j<len; j++)
			{
				switch(B[len-j-1]){
					case '0': y[j] = 0;
					break;
					case '1': y[j] = 1;
					break;
					case '2': y[j] = 2;
					break;
					case '3': y[j] = 3;
					break;
					case '4': y[j] = 4;
					break;
					case '5': y[j] = 5;
					break;
					case '6': y[j] = 6;
					break;
					case '7': y[j] = 7;
					break;
					case '8': y[j] = 8;
					break;
					case '9': y[j] = 9;
					break;
					case 'A': y[j] = 10;
					break;
					case 'B': y[j] = 11;
					break;
					case 'C': y[j] = 12;
					break;
					case 'D': y[j] = 13;
					break;
					case 'E': y[j] = 14;
					break;
					case 'F': y[j] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				};
				cnt2++;
			}

			object.addition(x, cnt1);
			object.addition(y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << sum[i] << " ";
			} */
			cout << endl;

			for(i=0; i<cnt; i++)
			{
				switch(sum[cnt-i-1]){
					case 0: ANS[i] = '0';
					break;
					case 1: ANS[i] = '1';
					break;
					case 2: ANS[i] = '2';
					break;
					case 3: ANS[i] = '3';
					break;
					case 4: ANS[i] = '4';
					break;
					case 5: ANS[i] = '5';
					break;
					case 6: ANS[i] = '6';
					break;
					case 7: ANS[i] = '7';
					break;
					case 8: ANS[i] = '8';
					break;
					case 9: ANS[i] = '9';
					break;
					case 10: ANS[i] = 'A';
					break;
					case 11: ANS[i] = 'B';
					break;
					case 12: ANS[i] = 'C';
					break;
					case 13: ANS[i] = 'D';
					break;
					case 14: ANS[i] = 'E';
					break;
					case 15: ANS[i] = 'F';
					break;
				};
			}
			ANS[cnt]='\0';
			i=0;
			while(ANS[i]=='0')
			{
				i++;
			}
			f=0;
			for(f=0; ANS[i]!='\0'; f++)
			{
				ANS[f] = ANS[i];
				i++;
			}
			ANS[f]='\0';
			cout << "SUM: " << ANS <<endl;
			break;


		case '-':
			cout << "Enter A: ";
			cin >> A;
			len = strlen(A);
			
			for(i=0; i<len; i++)
			{
				switch(A[len-i-1]){
					case '0': x[i] = 0;
					break;
					case '1': x[i] = 1;
					break;
					case '2': x[i] = 2;
					break;
					case '3': x[i] = 3;
					break;
					case '4': x[i] = 4;
					break;
					case '5': x[i] = 5;
					break;
					case '6': x[i] = 6;
					break;
					case '7': x[i] = 7;
					break;
					case '8': x[i] = 8;
					break;
					case '9': x[i] = 9;
					break;
					case 'A': x[i] = 10;
					break;
					case 'B': x[i] = 11;
					break;
					case 'C': x[i] = 12;
					break;
					case 'D': x[i] = 13;
					break;
					case 'E': x[i] = 14;
					break;
					case 'F': x[i] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				}
				cnt1++;
			}

			cout << "Enter B: ";
			cin >> B;
			len = strlen(B);
			
			for(j=0; j<len; j++)
			{
				switch(B[len-j-1]){
					case '0': y[j] = 0;
					break;
					case '1': y[j] = 1;
					break;
					case '2': y[j] = 2;
					break;
					case '3': y[j] = 3;
					break;
					case '4': y[j] = 4;
					break;
					case '5': y[j] = 5;
					break;
					case '6': y[j] = 6;
					break;
					case '7': y[j] = 7;
					break;
					case '8': y[j] = 8;
					break;
					case '9': y[j] = 9;
					break;
					case 'A': y[j] = 10;
					break;
					case 'B': y[j] = 11;
					break;
					case 'C': y[j] = 12;
					break;
					case 'D': y[j] = 13;
					break;
					case 'E': y[j] = 14;
					break;
					case 'F': y[j] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				}
				cnt2++;
			}

			object.difference(d, x, cnt1, e, y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << diff[i] << " ";
			} */
			cout << endl;

			for(i=0; i<cnt; i++)
			{
				switch(diff[cnt-i-1]){
					case 0: ANS[i] = '0';
					break;
					case 1: ANS[i] = '1';
					break;
					case 2: ANS[i] = '2';
					break;
					case 3: ANS[i] = '3';
					break;
					case 4: ANS[i] = '4';
					break;
					case 5: ANS[i] = '5';
					break;
					case 6: ANS[i] = '6';
					break;
					case 7: ANS[i] = '7';
					break;
					case 8: ANS[i] = '8';
					break;
					case 9: ANS[i] = '9';
					break;
					case 10: ANS[i] = 'A';
					break;
					case 11: ANS[i] = 'B';
					break;
					case 12: ANS[i] = 'C';
					break;
					case 13: ANS[i] = 'D';
					break;
					case 14: ANS[i] = 'E';
					break;
					case 15: ANS[i] = 'F';
					break;
				};
			}
			ANS[cnt]='\0';
			i=0;
			while(ANS[i]=='0')
			{
				i++;
			}
			f=0;
			for(f=0; ANS[i]!='\0'; f++)
			{
				ANS[f] = ANS[i];
				i++;
			}
			ANS[f]='\0';
			cout << "DIFFERENCE: " << ANS <<endl;
			break;

		case '*': 
			cout << "Enter A: ";
			cin >> A;
			len = strlen(A);
			
			for(i=0; i<len; i++)
			{
				switch(A[len-i-1]){
					case '0': x[i] = 0;
					break;
					case '1': x[i] = 1;
					break;
					case '2': x[i] = 2;
					break;
					case '3': x[i] = 3;
					break;
					case '4': x[i] = 4;
					break;
					case '5': x[i] = 5;
					break;
					case '6': x[i] = 6;
					break;
					case '7': x[i] = 7;
					break;
					case '8': x[i] = 8;
					break;
					case '9': x[i] = 9;
					break;
					case 'A': x[i] = 10;
					break;
					case 'B': x[i] = 11;
					break;
					case 'C': x[i] = 12;
					break;
					case 'D': x[i] = 13;
					break;
					case 'E': x[i] = 14;
					break;
					case 'F': x[i] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				}
				cnt1++;
			}

			cout << "Enter B: ";
			cin >> B;
			len = strlen(B);
			
			for(j=0; j<len; j++)
			{
				switch(B[len-j-1]){
					case '0': y[j] = 0;
					break;
					case '1': y[j] = 1;
					break;
					case '2': y[j] = 2;
					break;
					case '3': y[j] = 3;
					break;
					case '4': y[j] = 4;
					break;
					case '5': y[j] = 5;
					break;
					case '6': y[j] = 6;
					break;
					case '7': y[j] = 7;
					break;
					case '8': y[j] = 8;
					break;
					case '9': y[j] = 9;
					break;
					case 'A': y[j] = 10;
					break;
					case 'B': y[j] = 11;
					break;
					case 'C': y[j] = 12;
					break;
					case 'D': y[j] = 13;
					break;
					case 'E': y[j] = 14;
					break;
					case 'F': y[j] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				}
				cnt2++;
			}

			object.multiplication(x, cnt1, y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << mult[i] << " ";
			} */
			cout << endl;

			for(i=0; i<cnt; i++)
			{
				switch(mult[cnt-i-1]){
					case 0: ANS[i] = '0';
					break;
					case 1: ANS[i] = '1';
					break;
					case 2: ANS[i] = '2';
					break;
					case 3: ANS[i] = '3';
					break;
					case 4: ANS[i] = '4';
					break;
					case 5: ANS[i] = '5';
					break;
					case 6: ANS[i] = '6';
					break;
					case 7: ANS[i] = '7';
					break;
					case 8: ANS[i] = '8';
					break;
					case 9: ANS[i] = '9';
					break;
					case 10: ANS[i] = 'A';
					break;
					case 11: ANS[i] = 'B';
					break;
					case 12: ANS[i] = 'C';
					break;
					case 13: ANS[i] = 'D';
					break;
					case 14: ANS[i] = 'E';
					break;
					case 15: ANS[i] = 'F';
					break;
				};
			}
			ANS[cnt]='\0';
			i=0;
			while(ANS[i]=='0')
			{
				i++;
			}
			f=0;
			for(f=0; ANS[i]!='\0'; f++)
			{
				ANS[f] = ANS[i];
				i++;
			}
			ANS[f]='\0';
			cout << "PRODUCT: "<< ANS <<endl;
			break;

		case '/':
			cout << "Enter A: ";
			cin >> A;
			len = strlen(A);
			
			for(i=0; i<len; i++)
			{
				switch(A[len-i-1]){
					case '0': x[i] = 0;
					break;
					case '1': x[i] = 1;
					break;
					case '2': x[i] = 2;
					break;
					case '3': x[i] = 3;
					break;
					case '4': x[i] = 4;
					break;
					case '5': x[i] = 5;
					break;
					case '6': x[i] = 6;
					break;
					case '7': x[i] = 7;
					break;
					case '8': x[i] = 8;
					break;
					case '9': x[i] = 9;
					break;
					case 'A': x[i] = 10;
					break;
					case 'B': x[i] = 11;
					break;
					case 'C': x[i] = 12;
					break;
					case 'D': x[i] = 13;
					break;
					case 'E': x[i] = 14;
					break;
					case 'F': x[i] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				}
				cnt1++;
			}

			cout << "Enter B: ";
			cin >> B;
			len = strlen(B);
			
			for(j=0; j<len; j++)
			{
				switch(B[len-j-1]){
					case '0': y[j] = 0;
					break;
					case '1': y[j] = 1;
					break;
					case '2': y[j] = 2;
					break;
					case '3': y[j] = 3;
					break;
					case '4': y[j] = 4;
					break;
					case '5': y[j] = 5;
					break;
					case '6': y[j] = 6;
					break;
					case '7': y[j] = 7;
					break;
					case '8': y[j] = 8;
					break;
					case '9': y[j] = 9;
					break;
					case 'A': y[j] = 10;
					break;
					case 'B': y[j] = 11;
					break;
					case 'C': y[j] = 12;
					break;
					case 'D': y[j] = 13;
					break;
					case 'E': y[j] = 14;
					break;
					case 'F': y[j] = 15;
					break;
					default : cout << "invalid input" << endl;
							  goto label;
					break;
				}
				cnt2++;
			}

			object.division(x, cnt1, y, cnt2);
			
			/* for(i=0; i<cnt; i++)
			{
				cout << Division[i] << " ";
			} */
			cout << endl;
			

			for(i=0; i<T; i++)
			{
				switch(Division[T-i-1]){
					case 0: ANS[i] = '0';
					break;
					case 1: ANS[i] = '1';
					break;
					case 2: ANS[i] = '2';
					break;
					case 3: ANS[i] = '3';
					break;
					case 4: ANS[i] = '4';
					break;
					case 5: ANS[i] = '5';
					break;
					case 6: ANS[i] = '6';
					break;
					case 7: ANS[i] = '7';
					break;
					case 8: ANS[i] = '8';
					break;
					case 9: ANS[i] = '9';
					break;
					case 10: ANS[i] = 'A';
					break;
					case 11: ANS[i] = 'B';
					break;
					case 12: ANS[i] = 'C';
					break;
					case 13: ANS[i] = 'D';
					break;
					case 14: ANS[i] = 'E';
					break;
					case 15: ANS[i] = 'F';
					break;
				};
			}
			ANS[T]='\0';
			i=0;
			while(ANS[i]=='0')
			{
				i++;
			}
			f=0;
			for(f=0; ANS[i]!='\0'; f++)
			{
				ANS[f] = ANS[i];
				i++;
			}
			ANS[f]='\0';
			cout << "QOUTIENT: "<< ANS <<endl;
			break;


			

			

		case '#':
			cout << "Enter A: ";
			cin >> A;
			len = strlen(A);
			
			for(i=0; i<len; i++)
			{
				switch(A[len-i-1]){
					case '0': x[i] = 0;
					break;
					case '1': x[i] = 1;
					break;
					case '2': x[i] = 2;
					break;
					case '3': x[i] = 3;
					break;
					case '4': x[i] = 4;
					break;
					case '5': x[i] = 5;
					break;
					case '6': x[i] = 6;
					break;
					case '7': x[i] = 7;
					break;
					case '8': x[i] = 8;
					break;
					case '9': x[i] = 9;
					break;
					case 'A': x[i] = 10;
					break;
					case 'B': x[i] = 11;
					break;
					case 'C': x[i] = 12;
					break;
					case 'D': x[i] = 13;
					break;
					case 'E': x[i] = 14;
					break;
					case 'F': x[i] = 15;
					break;
					default : cout << "invalid input" << endl;
					break;
				}
				cnt1++;
			}

			cout << "Enter base of new system to convert to: ";
			cin >> c;

			object.interconvert(x, cnt1, c);


			for(i=0; i<T; i++)
			{
				// cout << conv[i] << " ";
				switch(conv[T-i-1]){
					case 0: ANS[i] = '0';
					break;
					case 1: ANS[i] = '1';
					break;
					case 2: ANS[i] = '2';
					break;
					case 3: ANS[i] = '3';
					break;
					case 4: ANS[i] = '4';
					break;
					case 5: ANS[i] = '5';
					break;
					case 6: ANS[i] = '6';
					break;
					case 7: ANS[i] = '7';
					break;
					case 8: ANS[i] = '8';
					break;
					case 9: ANS[i] = '9';
					break;
					case 10: ANS[i] = 'A';
					break;
					case 11: ANS[i] = 'B';
					break;
					case 12: ANS[i] = 'C';
					break;
					case 13: ANS[i] = 'D';
					break;
					case 14: ANS[i] = 'E';
					break;
					case 15: ANS[i] = 'F';
					break;
				}
			}
			ANS[T]='\0';
			i=0;
			while(ANS[i]=='0')
			{
				i++;
			}
			f=0;
			for(f=0; ANS[i]!='\0'; f++)
			{
				ANS[f] = ANS[i];
				i++;
			}
			ANS[f]='\0';
			cout << "ANSWER: "<<ANS << endl;
			break; 
		default : cout << "invalid operation";
		goto label;

		};
	} 

	else
	{
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

			object.addition(x, cnt1);
			object.addition(y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << sum[i];
			} */
			cout << endl; 

			for(i=0; i<cnt; i++)
			{
				ans = ans + pow(10,i) * sum[i];
			}

			cout << "SUM: " << ans <<endl;
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

			object.difference(d, x, cnt1, e, y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << diff[i];
			} */
			cout << endl;

			for(i=0; i<cnt; i++)
			{
				ans = ans + pow(10,i) * diff[i];
			}

			cout << "DIFFERENCE: " << ans <<endl;
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

			object.multiplication(x, cnt1, y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << mult[i];
			} */
			cout << endl;

			for(i=0; i<cnt; i++)
			{
				ans = ans + pow(10,i) * mult[i];
			}

			cout << "PRODUCT: " << ans <<endl;
			ans =0;
			break;

		case '/':
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

			object.division(x, cnt1, y, cnt2);

			/* for(i=0; i<cnt; i++)
			{
				cout << Division[i];
			} */
			cout << endl;

			for(i=0; i<T; i++)
			{
				ans = ans + pow(10,i) * Division[i];
			}

			cout << "DIVISION: " << ans <<endl;
			ans =0;
			break;

			

		case '#':
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

			cout << "Enter base of new system to convert to: ";
			cin >> c;

			object.interconvert(x, cnt1, c);

			for(i=0; i<T; i++)
			{
				// cout << conv[i] << " ";
				switch(conv[T-i-1]){
					case 0: ANS[i] = '0';
					break;
					case 1: ANS[i] = '1';
					break;
					case 2: ANS[i] = '2';
					break;
					case 3: ANS[i] = '3';
					break;
					case 4: ANS[i] = '4';
					break;
					case 5: ANS[i] = '5';
					break;
					case 6: ANS[i] = '6';
					break;
					case 7: ANS[i] = '7';
					break;
					case 8: ANS[i] = '8';
					break;
					case 9: ANS[i] = '9';
					break;
					case 10: ANS[i] = 'A';
					break;
					case 11: ANS[i] = 'B';
					break;
					case 12: ANS[i] = 'C';
					break;
					case 13: ANS[i] = 'D';
					break;
					case 14: ANS[i] = 'E';
					break;
					case 15: ANS[i] = 'F';
					break;
				}
			}
			ANS[T]='\0';
			cout << "ANSWER: " << ANS << endl;
			break; 

		
		default : cout << "invalid operation";
		goto label;

		};
	}

	cout << "Wanna continue? [Y/N]" << endl;
	cin >> ch;
	if(ch == 'N' | ch == 'n')
	{
		exit(0);
	}
	
	}
 
}
