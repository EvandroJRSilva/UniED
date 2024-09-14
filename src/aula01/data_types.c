#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  printf("\nShort int \t\t %lu Bytes \t %d a %d",sizeof(short int),SHRT_MIN,SHRT_MAX);
  printf("\nunsigned short int \t %lu Bytes \t 0 a %d",sizeof(unsigned short int),USHRT_MAX);
  printf("\nunsigned int \t\t %lu Bytes \t 0 a %u",sizeof(unsigned int),UINT_MAX);
  printf("\nint \t\t\t %lu Bytes \t %d a %d",sizeof(int),INT_MIN,INT_MAX);
  printf("\nlong int \t\t %lu Bytes \t %ld a %ld",sizeof(long int),LONG_MIN,LONG_MAX);
  printf("\nunsigned long int \t %lu Bytes \t 0 a %lu",sizeof(unsigned long int),ULONG_MAX);
  printf("\nlong long int \t\t %lu Bytes \t %lld a %lld", sizeof(long long int), LLONG_MIN, LLONG_MAX);
  printf("\nunsigned long long int \t %lu Bytes \t 0 a %llu \n\n",sizeof(unsigned long long int),ULLONG_MAX);

  //Character
  printf("\nCharacter \t\t %lu Bytes \t %d a %d",sizeof(char),CHAR_MIN,CHAR_MAX);
  printf("\nUnsigned Character \t %lu Bytes \t 0 a %d\n\n",sizeof(unsigned char),UCHAR_MAX);

  //Float
  printf("\nFloat \t\t %lu Bytes \t %g a %g",sizeof(float), FLT_MIN, FLT_MAX);
  printf("\nDouble \t\t %lu Bytes \t %g a %g",sizeof(double), DBL_MIN, DBL_MAX);
  printf("\nLong Double \t %lu Bytes \t %Lg a %Lg\n\n",sizeof(long double), LDBL_MIN, LDBL_MAX);

  return 0;
}