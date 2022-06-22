#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Year, Month and Day Coefficients, respectively
#define Y_C 372
#define M_C 31
#define D_C 1

long year_dot(int Y,int M,int D);
char* fmt_year(int Y,int M,int D);

int main(void)
{
  int last = 0;
  char* lastf = "0000-0-0";
  
  // Loops through every day from 0001-01-01 to 3000-12-31
  for (int Y = 1; Y <= 3000; Y++)
  {
    for (int M = 1; M <= 12; M++)
    {
      for (int D = 1; D <= 31; D++)
      {
        int date = year_dot(Y,M,D);
        char* datef = fmt_year(Y,M,D);

        if (date <= last)
        {
          printf("failed at %s(%d) vs %s(%d)\n",datef,date,lastf,last);
        }
        // else
        // {
        //   printf("succeeded at %s(%d) vs %s(%d)\n",datef,date,lastf,last);
        // }

        last = date;
        lastf = datef;
      }
    }
  }
  
}

long year_dot(int Y,int M,int D)
{
  // Returns the dot product: <Y, M, D> ・ <Y_C, M_C, D_C>
  return Y*Y_C + M*M_C + D*D_C;
}

char* fmt_year(int Y,int M,int D)
{
  // Returns date in ISO-8601 format (Y-M-D)
  // (Though YYYY-MM-DD would look a lot better)
  
  // https://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c
  int Y_len = snprintf( NULL, 0, "%d", Y );
  int M_len = snprintf( NULL, 0, "%d", M );
  int D_len = snprintf( NULL, 0, "%d", D );

  char* Y_str = malloc(Y_len+1);
  char* M_str = malloc(M_len+1);
  char* D_str = malloc(D_len+1);

  snprintf( Y_str, Y_len+1, "%d", Y );
  snprintf( M_str, M_len+1, "%d", M );
  snprintf( D_str, D_len+1, "%d", D );

  strcat(Y_str, "-");
  strcat(Y_str, M_str);
  strcat(Y_str, "-");
  strcat(Y_str, D_str);

  return Y_str;
}
