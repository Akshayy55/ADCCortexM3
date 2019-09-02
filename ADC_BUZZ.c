#include <LPC214X.H>
void adc_init(void);
unsigned short adc_read(void);
int main()
{	unsigned int val,val1;
	IO1DIR|=(1<<25);
	adc_init();
	while(1)
	{
		val = adc_read();
		val1=val>>2;
		IO1CLR=val1;
	}
}

void adc_init()
{
	PINSEL1 |= (PINSEL1 &~ (3<<28))|(1<<28);
}
unsigned short adc_read()
{
	 unsigned int data=0;
	 AD0CR=0x00200D00|(1<<3);
	 AD0CR|=0x01000000;
	 do{
	   data = AD0GDR;
	 }while((data & 0x80000000) == 0);
	 return (data >> 6) & 0x03FF;
}