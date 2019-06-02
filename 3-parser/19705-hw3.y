%{
#include <stdio.h>
void yyerror (const char *s) /* Called by yyparse on error */
{
//printf ("%s\n", s);
}
%}
%token tOPEN tCLOSE tSELF tEND tCOURSE tMEETING tITEM tCODE tSECTION tSTART tDAY tTYPE tCONSTRAINT tNAME tINSTRUCTOR tCRN tEND_A tCAPACITY tCLASS tMON tTUE tTHU tWED tFRI tTIME tSTRING tNUM
%%
prog: elementList
;
elementList: | element elementList
;
element: beginCourse classList endCourse
| beginConstraint itemList endConstraint
;
beginCourse: tOPEN tCOURSE courseAttrList tCLOSE
;
endCourse: tEND tCOURSE tCLOSE
;
courseAttrList: courseAttr
| courseAttr courseAttrList 
;
courseAttr: tCODE tSTRING
| tNAME tSTRING 
| tTYPE tSTRING
;
classList: class
| class classList
;
class: beginClass classAttrList endClass meetingList closeClass
;
beginClass: tOPEN tCLASS
;
endClass: tCLOSE
;
closeClass: tEND tCLASS tCLOSE
;
classAttrList: classAttr
| classAttr classAttrList
;
classAttr: tSECTION tSTRING
| tINSTRUCTOR tSTRING | tCRN tNUM | tCAPACITY tNUM
;
meetingList: meeting
| meeting meetingList
;
meeting: beginMeeting meetingAttrList endMeeting
;
beginMeeting: tOPEN tMEETING
;
endMeeting: tSELF
;
meetingAttrList: meetingAttr
| meetingAttr meetingAttrList
;
meetingAttr: tDAY day
| tSTART tTIME
| tEND_A tTIME
;
day: tMON
| tTUE
| tWED
| tTHU
| tFRI
; 
beginConstraint: tOPEN tCONSTRAINT tCLOSE
;
endConstraint: tEND tCONSTRAINT tCLOSE
;
itemList: item | item itemList
;
item: beginItem itemAttr endItem
;
beginItem: tOPEN tITEM
;
endItem: tSELF
;
itemAttr: tCODE tSTRING | tCRN tNUM
;
%%
int main ()
{
if (yyparse()) {
printf("ERROR\n");
return 1;
}
else {
printf("OK\n");
return 0;
}
}

