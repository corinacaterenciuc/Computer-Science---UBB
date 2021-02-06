%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(char *s);

#define YYDEBUG 1
%}

%token IDENTIFIER
%token CONSTANT
%token START
%token FINISH
%token IF
%token ELSE
%token ENDIF
%token FOR
%token FROM
%token TO
%token DO
%token ENDFOR
%token WHILE
%token ENDWHILE
%token GET
%token PRINT
%token INT
%token STRING
%token VECTOR
%token CONST
%token BOOL
%token CHAR
%token REAL
%token SQRT
%token COLON
%token SEMI_COLON
%token COMA
%token DOT
%token LEFT_ROUND_PARENTHESIS
%token RIGHT_ROUND_PARENTHESIS
%token LEFT_SQUARE_PARENTHESIS
%token RIGHT_SQUARE_PARENTHESIS
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVISION
%token LESS_THAN
%token GREATER_THAN
%token LESS_OR_EQUAL_THAN
%token GREATER_OR_EQUAL_THAN
%token DIFFERENT
%token ASSIGNMENT
%token EQUAL
%token POWER
%token OR
%token AND
%token NOT

%start program

%%

program : START dec_list stmt_list FINISH  ;
dec_list : declaration SEMI_COLON ;
dec_list : declaration SEMI_COLON dec_list ;
declaration :  type id_list ;
id_list :  IDENTIFIER ;
id_list :  IDENTIFIER COMA id_list ;
type_1 :  BOOL ;
type_1 : CHAR ;
type_1 : STRING ;
type_1 : CONST ;
type_1 : INT ;
type_1 : REAL ;
vector_decl : type_1 VECTOR LEFT_SQUARE_PARENTHESIS CONSTANT RIGHT_SQUARE_PARENTHESIS ;
type : type_1 ;
type : vector_decl ;
stmt_list : stmt ;
stmt_list : stmt stmt_list ;
stmt : simple_stmt SEMI_COLON ;
stmt : struct_stmt ;
simple_stmt : assignmnt ;
simple_stmt : io_stmt ;
assignmnt : IDENTIFIER ASSIGNMENT expression ;
assignmnt : elem_vector ASSIGNMENT expression ;
expression : term ;
expression : term operation expression ;
expression : unary_operation expression ;
unary_operation : NOT ;
unary_operation : SQRT ;
operation : PLUS
		| MINUS
		| MULTIPLY
		| DIVISION
		| AND
		| OR
		| POWER ;
term : IDENTIFIER ;
term : CONSTANT ;
term : elem_vector ;
elem_vector : IDENTIFIER LEFT_SQUARE_PARENTHESIS CONSTANT RIGHT_SQUARE_PARENTHESIS ;
elem_vector : IDENTIFIER LEFT_SQUARE_PARENTHESIS IDENTIFIER RIGHT_SQUARE_PARENTHESIS ;
io_stmt : GET id_list ;
io_stmt : PRINT id_list ;
struct_stmt : while_stmt ;
struct_stmt : if_stmt ;
struct_stmt : for_stmt ;
while_stmt : WHILE condition COLON stmt_list ENDWHILE ;
if_stmt : IF condition COLON stmt_list ENDIF ;
if_stmt : IF condition COLON stmt_list ELSE COLON stmt_list ENDIF ;
for_stmt : FOR IDENTIFIER FROM CONSTANT TO CONSTANT COLON stmt_list ENDFOR ;
for_stmt : FOR IDENTIFIER FROM CONSTANT TO IDENTIFIER COLON stmt_list ENDFOR ;
condition : expression relation expression ;
relation : LESS_THAN
		| GREATER_THAN
		| LESS_OR_EQUAL_THAN
		| GREATER_OR_EQUAL_THAN
		| DIFFERENT
		| EQUAL ;

%%

void yyerror(char *s)
{
  printf("%s\n", s);
}

extern FILE *yyin;

int main(int argc, char **argv)
{
  if (argc > 1)
    yyin = fopen(argv[1], "r");
  if ( (argc > 2) && ( !strcmp(argv[2], "-d") ) )
    yydebug = 1;
  if ( !yyparse() )
    fprintf(stderr,"\t Program accepted !!!\n");
}