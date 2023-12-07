#include "main.h"


/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */


int _printf(const char *format, ...){

   int char_word =0;

   va_list (argu_ments);

   if (format == NULL){
      return (-1);
   }


   va_start(argu_ments, format);


   while (*format){
      if(*format != '%'){
         write(1, format, 1);
         char_word++;
      }
      else{
         format++;
         if(*format == '\0'){
         break;
         }
         if(*format == '%'){
            write(1, format, 1);
            char_word++;
         }
         else if(*format == 'c'){
         char c = va_arg(argu_ments, int);
         write(1, &c, 1);
         char_word++;
         }
         
         else if(*format == 's'){
            char *str = va_arg(argu_ments, char*);
            int str_len = 0;

            while (str[str_len] != '\0')
            str_len++;
            
            write(1, str, str_len);
            char_word += str_len;
         }
      }

      format++;
   }

   va_end(argu_ments);

   return char_word;
}

int main(){
   _printf("fatimah\n");
   _printf("%c\n", 'F');
   _printf("%s\n", "string");
   _printf("%%\n");
   return 0;
}
