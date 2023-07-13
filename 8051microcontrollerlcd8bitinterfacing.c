#include <REGX52.H>  //8-bit
#define LCD_dat P2
sbit rs = P3^5;
sbit en = P3^3;

void delay(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);

void main(void)
{
lcd_cmd(0x38);
lcd_cmd(0x0C);
while(1)
{
lcd_cmd(0x80);
//lcd_data('W');
lcd_str("EMBEDDED SYSTEMS");
lcd_cmd(0xC0);
lcd_str("WELCOME VINAY!");
lcd_cmd(0x01);
lcd_str("HELLO WORLD!");
lcd_cmd(0xC0);
lcd_str("ALL THE BEST..");

}

}
void lcd_str(unsigned char *str)
{
unsigned int loop = 0;
for (loop = 0;str[loop]!='\0';loop++)
{
lcd_data(str[loop]);
}
}
void lcd_data(unsigned char ch)
{
LCD_dat = ch;
rs = 1;
en = 1;
delay(10);
en = 0;
}

void lcd_cmd(unsigned char ch)
{
LCD_dat = ch;
rs = 0;
en = 1;
delay(10);
en = 0;
}

void delay(unsigned int dly)
{
unsigned int loop = 0;
unsigned int delay_gen=0;
for(loop = 0; loop<dly;loop++)
for(delay_gen=0; delay_gen<1000; delay_gen++);
}

