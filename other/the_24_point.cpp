#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double add( double a, double b )
{
	return a+b;
}

double sub( double a, double b )
{
	return a-b;
}

double mul( double a, double b )
{
	return a*b;
}

double div( double a, double b )
{
	return a/b;
}

bool cal( double *num )
{
	char sign[] = { '+', '-', '*', '/' };
	double (*oper[])( double, double ) = { add, sub, mul, div };
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
		{
			for ( int k = 0; k < 4; k++ )
			{
				if ( fabs( oper[j](oper[i](num[0],num[1]),oper[k](num[2],num[3]))-24 ) < 10e-6 )
				{
					printf( "(%.0lf%c%.0lf)%c(%.0lf%c%.0lf)\n", num[0], sign[i], num[1], sign[j], num[2], sign[k], num[3] );
					return 1;
				}//(a+b)+(b+c)

				if ( fabs( oper[k](oper[j](oper[i](num[0],num[1]),num[2]),num[3])-24 ) < 10e-6 )
				{
					printf( "((%.0lf%c%.0lf)%c%.0lf)%c%.0lf\n", num[0], sign[i], num[1], sign[j], num[2], sign[k], num[3] );
					return 1;
				}//((a+b)+c)+d
				if ( fabs( oper[k](oper[i](num[0],oper[j](num[1],num[2])),num[3])-24 ) < 10e-6 )
				{
					printf( "(%.0lf%c(%.0lf%c%.0lf))%c%.0lf\n", num[0], sign[i], num[1], sign[j], num[2], sign[k], num[3] );
					return 1;
				}//(a+(b+c))+d
				if ( fabs( oper[i](num[0],oper[k](oper[j](num[1],num[2]),num[3]))-24 ) < 10e-6 )
				{
					printf( "%.0lf%c((%.0lf%c%.0lf)%c%.0lf)\n", num[0], sign[i], num[1], sign[j], num[2], sign[k], num[3] );
					return 1;
				}//a+((b+c)+d)
				if ( fabs( oper[i](num[0],oper[j](num[1],oper[k](num[2],num[3])))-24 ) < 10e-6 )
				{
					printf( "%.0lf%c(%.0lf%c(%.0lf%c%.0lf))\n", num[0], sign[i], num[1], sign[j], num[2], sign[k], num[3] );
					return 1;
				}//a+(b+(c+d))
			}
		}
	}
	return 0;
}

int main( void )
{
	double num[4];
	while ( scanf( "%lf%lf%lf%lf", &num[0], &num[1], &num[2], &num[3] ) != EOF )
	{
		int flag = 0;
		sort( num, num+4 );
		do
		{
			flag = cal( num );
			if ( flag )
				break;
		}while ( next_permutation( num, num+4 ) );
		if ( !flag )
			printf( "what a pity!\n" );
	}
	return 0;
}
