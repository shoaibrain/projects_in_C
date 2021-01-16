//Name: Shoaib Rain
//Student ID: 1001825785

#include <stdio.h>
#define BITS 8

//Function to convert decimal to binary
void ConvertDecimalToBinary(int num, char chararr[])
{
  int arr[BITS] = {} ;
  int a, arrayIndex;
  a=BITS; // Bits is set to 8    

  for (arrayIndex = 0; arrayIndex < BITS; arrayIndex++)
  {
      if (num >= 1)
      {
          arr[a-1] = num; 
          num = num >> 1;
          a--;
      }
  }

  int i;
  for (i = 0; i < BITS; i++)
  {
      if ((arr[i]&1)==0)
      {
          chararr[i]=48;
      }
      else
      {
          chararr[i]=49;
      }
  }

}


int main(void) {
  //Instruction Statements
  printf("Bitwise Calculator\n\n");
  printf("Enter two base 10 values with a bitwise operator to see the decimal result and the binary result. The format is\n\nFirstNumber BitwiseOperator SecondNumber\n\nFor example, enter the expression\n\n2 & 3\n\n");
  printf("This calculator can used with &, |, ^, << and >>\n\n");
  printf("Please note that the spaces between numbers and operator is essential\nand the two entered values must be between 0 and 255\n\n");

  // declare variables
  int num1,num2;
  char bit_operator[3] = {};
  
  // Char array of length BITS+1
  char arr[BITS+1] = {};
 
  // Prompt and store the values
  printf("Enter the expression: ");
  scanf("%d %s %d", &num1, bit_operator, &num2);

  // Keep asking for input unless the condition is satisfied
  while((num1 < 0 || num1 > 255) || (num2 < 0 || num2 > 255))
  {
      printf("Your number should be within the range of 0 and 255\n");
      printf("Enter the expression: ");
      scanf("%d %s %d", &num1, bit_operator, &num2);
  }
  
  if (bit_operator[0] == '&')
  {
      printf("In base 10 ....\n");
      printf("%d & %d = %d",num1, num2, num1&num2);

  } 
  else if (bit_operator[0] == '|')
  {
      printf("In base 10 ....\n");
      printf("%d | %d = %d",num1,num2, num1|num2);
  } 
  else if (bit_operator[0] == '^')
  {
      printf("In base 10 ....\n");
      printf("%d ^ %d = %d",num1, num2, num1^num2);
  } 
  else if (bit_operator[0] == '>') 
  {
      printf("In base 10 ....\n");
      printf("%d >> %d = %d",num1, num2, num1>>num2);
  }
  else if (bit_operator[0] == '<') 
  {
      printf("In base 10 ....\n");
      printf("%d << %d = %d",num1, num2, num1<<num2);
  } 
  else
  {
      printf("Operator %s is not supported by this calculator", bit_operator);
  } 


//Print answers
  if (bit_operator[0] == '&')
  {
      printf("\n\nIn %d-bit base 2...\n\n",BITS);
      ConvertDecimalToBinary(num1,arr);
      printf("%10s", arr);
      printf("\n%s\n", bit_operator);
    
      ConvertDecimalToBinary(num2,arr);
      printf("%10s", arr);

      printf("\n  ========\n");
      ConvertDecimalToBinary(num1&num2,arr);
      printf("%10s", arr);
      printf("\n");
  }


  if (bit_operator[0] == '|')
  {
      printf("\n\nIn %d-bit base 2...\n\n",BITS);
      ConvertDecimalToBinary(num1,arr);
      printf("%10s", arr);
      
	  printf("\n%s\n", bit_operator);

      ConvertDecimalToBinary(num2,arr);
      printf("%10s", arr);
      
      printf("\n  ========\n");

      ConvertDecimalToBinary(num1|num2,arr);
      printf("%10s", arr);
      printf("\n");
  }
  
  if (bit_operator[0] == '^')
  {    
      printf("\n\nIn %d-bit base 2...\n\n",BITS);
      ConvertDecimalToBinary(num1,arr);
      printf("%10s", arr);
      printf("\n%s\n", bit_operator);

      
      ConvertDecimalToBinary(num2,arr);
      printf("%10s", arr);

      printf("\n  ========\n");
	  
      ConvertDecimalToBinary(num1^num2,arr);
      printf("%10s", arr);
      printf("\n");
  }

  if (bit_operator[0] == '>')
  {
      printf("\n\nIn %d-bit base 2...\n\n",BITS);
      ConvertDecimalToBinary(num1,arr);
      printf("%s", arr);
      printf(" %s %d\n", bit_operator, num2);

      ConvertDecimalToBinary(num1>>num2,arr);
      printf("%s", arr);
      printf("\n");
  }

  if (bit_operator[0] == '<')
  {
      printf("\n\nIn %d-bit base 2...\n\n",BITS);
      ConvertDecimalToBinary(num1,arr);
      printf("%s", arr);
      printf(" %s %d\n\n", bit_operator, num2);
      
      ConvertDecimalToBinary(num1<<num2,arr); 
      printf("%s", arr);
      printf("\n");
  }
  
  return 0;

}