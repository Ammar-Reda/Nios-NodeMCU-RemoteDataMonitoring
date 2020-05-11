#include <stdio.h>
#include <math.h>
#include "system.h"
#include "altera_avalon_spi.h"
#include <time.h>

void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);
void send_char(volatile int *, char);

volatile int * UART_ptr 	= (int *) RS232_0_BASE;	//  RS232 UART address

int main(){

while(1){
    
	alt_u8 startBit = 0x01;
	alt_u16 reading;
	alt_u8 rec[2];
	float finalReading;
	int i;
	char buf[10];


	alt_avalon_spi_command(SPI_0_BASE ,0 , 1, &startBit, 2, &rec, 0);

	reading = ((rec[0] & 0x03) << 8) + (rec[1]);
	finalReading = (3.3 *  (float) reading)/ 1023;
	ftoa(finalReading, buf, 3);

	send_char(UART_ptr, (char) 's');

	for (i = 0; i < 5; ++i)
		send_char(UART_ptr, buf[i]);

	usleep(1000000);
}
  return 0;
}

void send_char( volatile int * UART_ptr, char c )
{
	int control;
	control = *(UART_ptr + 1);			// read the UART control register
	if (control & 0x00FF0000)			// if space, then send character, else ignore
		*(UART_ptr) = c;
}

// Reverses a string 'str' of length 'len'
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Converts a given integer x to string str[].
// d is the number of digits required in the output.
// If d is more than the number of digits in x,
// then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i = 0;
    if(x==0){
        str[i]= '0';
        i++;
    }
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating-point/double number to a string.
void ftoa(float n, char* res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
