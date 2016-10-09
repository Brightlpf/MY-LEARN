#include<stdio.h>

int main(void)
{
 unsigned char num_array[4] = {0x08, 0x10, 0x25, 0x43};
 int num;
 unsigned char num_new;
 num = 0x8102543;
 for (int i = 0; i < 4; i++)
 {
  printf("num_array[%d] = %x, Address = %p\n", i, num_array[i], &num_array[i]);
 }
 for (int i = 0; i < 4; i++)
 {
  num_new = *((unsigned char*)&num + i);
  printf("num: the %d byte is %x, Address = %p\n", i, num_new, &num_new+i);
 }
 return 0;
}