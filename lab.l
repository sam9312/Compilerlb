%{
	#include <stdio.h>
	#include <stdlib.h>
	int i, line =1;
	FILE *f_keyword,*f_integer.*f_variable,*f_other_keyword,*f_string_const;
	void my_function_keyword(char *enter);
	void my_function_other_keyword(char *enter);
	void my_function_string_const(char *enter);
	void my_function_integer(char *enter);
	void my_function_variable(char *enter);
	void my_function_new_line();
}%

comment "//".*
whitespace [ ]
uc [A-Z]
lc [a-z]
letter {uc}|{lc} 

new_line [\n]       
ascii  [^.\"\n]
digit  [0-9]


variable {lc}({lc}|{digit})*
integer     ({digit}|{hex}|{oct})+
string_const     \"({ascii})*\"

other [#",.;{}()=><\-*+]
keyword    for|if|else
other_keyword  auto|break|case|char|const|continue|default|do|double|enum|extern|float|goto|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while

%%
{comment}		{ }
{whitespace}	{ }
{other}		{ }
{keyword}	{ my_function_keyword(yytext) ;}
{other_keyword}		{ my_function_other_keyword(yytext);}
{string_const}		{ my_function_string_const(yytext);}
{integer}		{ my_function_integer(yytext);}
{variable}		{ my_function_variable(yytext);}
{new_line}		{ my_function_new_line();}

%%

int main(){
	f_keyword=fopen("keywords.txt","w");
	f_integer=fopen("integer.txt","w"); 
	f_other_keyword=fopen("other_keyword.txt","w"); 
	f_variable=fopen("variable.txt","w"); 
	f_string_const=fopen("string_const.txt","w"); 

	yylex();

	   fclose(f_keyword);
	   fclose(f_integer);
	  fclose(f_other_keyword);
	   fclose(f_variable);
	   fclose(f_string_const);
	   
	return 0;
}

int yywrap(){
	return 1;
}

void my_function_keyword(char *enter){
	fprintf(f_keyword,"%s\t\t\t\t%d\n",enter,line);
}
void my_function_other_keyword(char *enter){
	fprintf(f_keyword,"%s\t\t\t\t%d\n",enter,line);
	}
void my_function_string_const(char *enter){
	fprintf(f_keyword,"%s\t\t\t\t%d\n",enter,line);
	}
void my_function_integer(char *enter){
	fprintf(f_keyword,"%s\t\t\t\t%d\n",enter,line);
	}
void my_function_variable(char *enter){
	fprintf(f_keyword,"%s\t\t\t\t%d\n",enter,line);
	}
void my_function_new_line(){
		line++;
	}