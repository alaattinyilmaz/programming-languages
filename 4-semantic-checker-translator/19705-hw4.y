%{
	#include <stdio.h>
	#include "19705-hw4.h"

	struct TreeNode * root;
	void yyerror(const char *s){//called by yyparse on error
		printf("%s\n", s);
	}
	
	extern int noOfLine;
	extern int lineOfCourse;
	extern int lineOfClass;
	extern int lineOfMeeting;
	extern int courseCount;
	extern int classCount;
	extern int meetingCount;
	int errorFlag = 0;
	struct CourseCheck headCourseCheck;
%}

%union {
char * str;
struct TreeNode * treePtr;
}

%token tOPEN tCOURSE tCLOSE tEND tCODE tCLASS  tNAME tTYPE tSTRING tNUM tSECTION  tINSTRUCTOR tCRN  tCAPACITY tMEETING tSELF tDAY tSTART tTIME  tEND_A tMON  tTUE  tWED  tTHU  tFRI tCONSTRAINT tITEM 
%type <treePtr>	prog elementList element beginCourse endCourse courseAttrList courseAttr classList class beginClass endClass closeClass classAttrList classAttr meetingList meeting beginMeeting endMeeting meetingAttrList meetingAttr day beginConstraint endConstraint itemList item beginItem endItem itemAttr
%type <str> tOPEN tCOURSE tCLOSE tEND tCODE tCLASS tNAME tTYPE tSTRING tNUM tSECTION tINSTRUCTOR tCRN tCAPACITY tMEETING tSELF tDAY tSTART tTIME  tEND_A tMON tTUE tWED tTHU tFRI tCONSTRAINT tITEM 
%%

prog :  elementList { root = mkProg1( $1 ); } | { root = mkProg2(); };
elementList :  element { $$ = mkElementList1( $1 ); } | element elementList { $$ = mkElementList2( $1 , $2 ); } ;
element : beginCourse classList endCourse { $$ = mkElement1( $1 , $2 , $3 ); } | beginConstraint itemList endConstraint { $$ = mkElement2( $1 , $2 , $3 ); } ;
beginCourse : tOPEN tCOURSE courseAttrList tCLOSE { $$ = mkBeginCourse( $1 , $2 , $3 , $4 ); } ;
endCourse : tEND tCOURSE tCLOSE { $$ = mkEndCourse( $1 , $2 , $3 ); };
courseAttrList :  courseAttr { $$ = mkCourseAttrList1 ( $1 ); } |  courseAttr courseAttrList { $$ = mkCourseAttrList2 ( $1 , $2 ); };
courseAttr : tCODE tSTRING { $$ = mkCourseAttr( $1 , $2 ); } | tNAME tSTRING { $$ = mkCourseAttr( $1 , $2 ); } | tTYPE tSTRING { $$ = mkCourseAttr( $1 , $2 ); };
classList : class { $$ = mkClassList1( $1 ); } | class classList { $$ = mkClassList2( $1 , $2 ); };
class :  beginClass classAttrList endClass meetingList closeClass { $$ = mkClass( $1 , $2 , $3 , $4 , $5 ); };
beginClass  : tOPEN tCLASS { $$ = mkBeginClass( $1 , $2 ); };
endClass :  tCLOSE { $$ = mkEndClass( $1 ); };
closeClass : tEND tCLASS tCLOSE { $$ = mkCloseClass( $1 , $2 , $3 ); } ;
classAttrList :  classAttr { $$ = mkClassAttrList1( $1 ); }| classAttr classAttrList { $$ = mkClassAttrList2( $1 , $2 ); };
classAttr : tSECTION tSTRING { $$ = mkClassAttr( $1 , $2 ); } | tINSTRUCTOR tSTRING { $$ = mkClassAttr( $1 , $2 ); } | tCRN tNUM { $$ = mkClassAttr( $1 , $2 ); } | tCAPACITY tNUM { $$ = mkClassAttr( $1 , $2 ); };
meetingList : meeting { $$ = mkMeetingList1( $1 ); } | meeting meetingList { $$ = mkMeetingList2( $1 , $2 ); };
meeting : beginMeeting meetingAttrList endMeeting { $$ = mkMeeting( $1 , $2 , $3 ); };
beginMeeting :  tOPEN tMEETING { $$ = mkBeginMeeting( $1 , $2 ); };
endMeeting :tSELF { $$ = mkEndMeeting( $1 ); };
meetingAttrList : meetingAttr { $$ = mkMeetingAttrList1( $1 ); } | meetingAttr meetingAttrList { $$ = mkMeetingAttrList2( $1, $2 ); } ;
meetingAttr : tDAY day { $$ = mkMeetingAttr1( $1, $2 ); } | tSTART tTIME { $$ = mkMeetingAttr2( $1, $2 ); } | tEND_A tTIME { $$ = mkMeetingAttr2( $1, $2 ); };
day : tMON { $$ = mkDay( $1 ); } | tTUE { $$ = mkDay( $1 ); } | tWED { $$ = mkDay( $1 ); } | tTHU { $$ = mkDay( $1 ); } | tFRI { $$ = mkDay( $1 ); } ;
beginConstraint : tOPEN tCONSTRAINT tCLOSE { $$ = mkBeginConstraint( $1 , $2 , $3 ); } ;
endConstraint : tEND tCONSTRAINT tCLOSE { $$ = mkEndConstraint( $1 , $2 , $3 ); } ;
itemList :  item { $$ = mkItemList1( $1 ); } | item itemList { $$ = mkItemList2( $1 , $2 ); } ;
item :  beginItem itemAttr endItem { $$ = mkItem( $1 , $2 , $3 ); };
beginItem : tOPEN tITEM { $$ = mkBeginItem( $1 , $2 ); } ;
endItem : tSELF { $$ = mkEndItem( $1 ); } ;
itemAttr: tCODE tSTRING { $$ = mkItemAttr( $1 , $2 ); } | tCRN tNUM { $$ = mkItemAttr( $1 , $2 ); };

%%
int main(){
	if(yyparse()){
		printf("ERROR\n");
		return 1;		
	}else{
		PrintTree(root);
		return 0;
	}	
} 
