#ifndef __19705_HW4_H__
#define __19705_HW4_H__

typedef enum { PROG1, PROG2, ELEMENTLIST1, ELEMENTLIST2, ELEMENT1, ELEMENT2, BEGINCOURSE, ENDCOURSE, COURSEATTRLIST1, COURSEATTRLIST2, COURSEATTR, CLASSLIST1, CLASSLIST2, CLASSN, BEGINCLASS, ENDCLASS, CLOSECLASS, CLASSATTRLIST1, CLASSATTRLIST2, CLASSATTR, MEETINGLIST1, MEETINGLIST2, MEETING, BEGINMEETING, ENDMEETING, MEETINGATTRLIST1, MEETINGATTRLIST2, MEETINGATTR1, MEETINGATTR2, DAY, BEGINCONSTRAINT, ENDCONSTRAINT, ITEMLIST1, ITEMLIST2, ITEM, BEGINITEM, ENDITEM, ITEMATTR} NodeType;

typedef struct CourseCheck{
	int cocc;
	int nocc;
	int tocc;
	int lineCount;
	struct CourseCheck * next;
} CourseCheck;

/*
typedef struct classCheck{
	NodeType nodeType;
	union ChosenNode * chosenNode;
} TreeNode;

typedef struct meetingCheck{
	NodeType nodeType;
	union ChosenNode * chosenNode;
} TreeNode;
*/

typedef struct TreeNode{
	NodeType nodeType;
	union ChosenNode * chosenNode;
} TreeNode;

typedef struct Prog1Node{
	struct TreeNode * elementList;
} Prog1Node;

typedef struct Prog2Node{
	char * epsilon;
} Prog2Node;

typedef struct ElementList1Node{
	struct TreeNode * element;
} ElementList1Node;

typedef struct ElementList2Node{
	struct TreeNode * element;
	struct TreeNode * elementList;
} ElementList2Node;


typedef struct Element1Node{
	struct TreeNode * beginCourse;
	struct TreeNode * classList;
	struct TreeNode * endCourse;
} Element1Node;

typedef struct Element2Node{
	struct TreeNode * beginConstraint;
	struct TreeNode * itemList;
	struct TreeNode * endConstraint;
} Element2Node;

typedef struct BeginCourseNode{
	char * tOpen;
	char * tCourse;
	struct TreeNode * courseAttrList;
	char * tClose;
	struct CourseCheck * courseCheck;
} BeginCourseNode;

typedef struct EndCourseNode{
	char * tEnd;
	char * tCourse;
	char * tClose;
} EndCourseNode;

typedef struct CourseAttrList1Node{
	struct TreeNode * courseAttr;
} CourseAttrList1Node;

typedef struct CourseAttrList2Node{
	struct TreeNode * courseAttr;
	struct TreeNode * courseAttrList;
} CourseAttrList2Node;

typedef struct CourseAttrNode{
	char * tCourseAttrType; // TODO: CHECK AGAIN MAYBE THREE CASES?
	char * tString;
} CourseAttrNode;

// ClassList
typedef struct ClassList1Node{
	struct TreeNode * classN;
} ClassList1Node;

typedef struct ClassList2Node{
	struct TreeNode * classN;
	struct TreeNode * classList;
} ClassList2Node;

typedef struct ClassNode{
	struct TreeNode * beginClass;
	struct TreeNode * classAttrList;
	struct TreeNode * endClass;
	struct TreeNode * meetingList;
	struct TreeNode * closeClass;
} ClassNode;

typedef struct BeginClassNode{
	char * tOpen;
	char * tClass;
} BeginClassNode;

typedef struct EndClassNode{
	char * tClose;
} EndClassNode;

typedef struct CloseClassNode{
	char * tEnd;
	char * tClass;
	char * tClose;
} CloseClassNode;

typedef struct ClassAttrList1Node{
	struct TreeNode * classAttr;
} ClassAttrList1Node;

typedef struct ClassAttrList2Node{
	struct TreeNode * classAttr;
	struct TreeNode * classAttrList;
} ClassAttrList2Node;

typedef struct ClassAttrNode{
	char * classAttrType; // TODO: THINK AGAIN
	char * tString;
} ClassAttrNode;

typedef struct MeetingList1Node{
	struct TreeNode * meeting;
} MeetingList1Node;

typedef struct MeetingList2Node{
	struct TreeNode * meeting;
	struct TreeNode * meetingList;
} MeetingList2Node;

typedef struct MeetingNode{
	struct TreeNode * beginMeeting;
	struct TreeNode * meetingAttrList;
	struct TreeNode * endMeeting;
} MeetingNode;

typedef struct BeginMeetingNode{
	char * tOpen;
	char * tMeeting;
} BeginMeetingNode;

typedef struct EndMeetingNode{
	char * tSelf;
} EndMeetingNode;

typedef struct MeetingAttrList1Node{
	struct TreeNode * meetingAttr;
} MeetingAttrList1Node;

typedef struct MeetingAttrList2Node{
	struct TreeNode * meetingAttr;
	struct TreeNode * meetingAttrList;
} MeetingAttrList2Node;

typedef struct MeetingAttr1Node{
	char * tDay;
	struct TreeNode * day;
} MeetingAttr1Node;

typedef struct MeetingAttr2Node{
	char * meetingAttrType; // tSTART or t_END_A
	char * tTime;
} MeetingAttr2Node;

typedef struct DayNode{
	char * tDayType; // tMON / tTUE ...
} DayNode;

typedef struct BeginConstraintNode{
	char * tOpen;
	char * tConstraint;
	char * tClose;
} BeginConstraintNode;

typedef struct EndConstraintNode{
	char * tEnd;
	char * tConstraint;
	char * tClose;
} EndConstraintNode;

typedef struct ItemList1Node{
	struct TreeNode * item;
} ItemList1Node;

typedef struct ItemList2Node{
	struct TreeNode * item;
	struct TreeNode * itemList;
} ItemList2Node;

typedef struct ItemNode{
	struct TreeNode * beginItem;
	struct TreeNode * itemAttr;
	struct TreeNode * endItem;
} ItemNode;

typedef struct BeginItemNode{
	char * tOpen;
	char * tItem;
} BeginItemNode;

typedef struct EndItemNode{
	char * tSelf;
} EndItemNode;

typedef struct ItemAttrNode{
	char * itemAttrType; // tCODE or tCRN
	char * tStInt; // tSTRING or tNUM
} ItemAttrNode;

typedef union ChosenNode{
	Prog1Node progNode1;
	Prog2Node progNode2;
	ElementList1Node elementListNode1;
	ElementList2Node elementListNode2;
	Element1Node elementNode1;
	Element2Node elementNode2;
	BeginCourseNode beginCourseNode;
	EndCourseNode endCourseNode;
	CourseAttrList1Node courseAttrList1Node;
	CourseAttrList2Node courseAttrList2Node;
	CourseAttrNode courseAttrNode;
	ClassList1Node classList1Node;
	ClassList2Node classList2Node;
	ClassNode classNode;
	BeginClassNode beginClassNode;
	EndClassNode endClassNode;
	CloseClassNode closeClassNode;
	ClassAttrList1Node classAttrList1Node;
	ClassAttrList2Node classAttrList2Node;
	ClassAttrNode classAttrNode;
	MeetingList1Node meetingList1Node;
	MeetingList2Node meetingList2Node;
	MeetingNode meetingNode;
	BeginMeetingNode beginMeetingNode;
	EndMeetingNode endMeetingNode;
	MeetingAttrList1Node meetingAttrList1Node;
	MeetingAttrList2Node meetingAttrList2Node;
	MeetingAttr1Node meetingAttr1Node;
	MeetingAttr2Node meetingAttr2Node;
	DayNode dayNode;
	BeginConstraintNode beginConstraintNode;
	EndConstraintNode endConstraintNode;
	ItemList1Node itemList1Node;
	ItemList2Node itemList2Node;
	ItemNode itemNode;
	BeginItemNode beginItemNode;
	EndItemNode endItemNode;
	ItemAttrNode itemAttrNode;
} ChosenNode;


	TreeNode * mkProg1 (TreeNode * elementList);
	TreeNode * mkProg2 ();
	TreeNode * mkElementList1 (TreeNode * element);
	TreeNode * mkElementList2 (TreeNode * element, TreeNode * elementList);
	TreeNode * mkElement1 (TreeNode * beginCourse, TreeNode * classList, TreeNode * endCourse);
	TreeNode * mkElement2 (TreeNode * beginConstraint, TreeNode * endConstraint, TreeNode * itemList);
	TreeNode * mkBeginCourse (char * tClose , char * tCourse, TreeNode * courseAttrList, char * tOpen);
	TreeNode * mkEndCourse (char * tEnd , char * tCourse, char * tClose);
	TreeNode * mkCourseAttrList1 (TreeNode * courseAttr);
	TreeNode * mkCourseAttrList2 (TreeNode * courseAttr, TreeNode * courseAttrList);
	TreeNode * mkCourseAttr (char * tCourseAttrType, char * tString);
	TreeNode * mkClassList1 (TreeNode * classN);
	TreeNode * mkClassList2 (TreeNode * classN, TreeNode * classList);
	TreeNode * mkClass (TreeNode * beginClass, TreeNode * classAttrList, TreeNode * endClass, TreeNode * meetingList, TreeNode * closeClass);
	TreeNode * mkBeginClass (char * tOpen, char * tClass);
	TreeNode * mkEndClass (char * tClose);
	TreeNode * mkCloseClass (char * tEnd, char * tClass, char * tClose);
	TreeNode * mkClassAttrList1 (TreeNode * classAttr);
	TreeNode * mkClassAttrList2 (TreeNode * classAttr, TreeNode * classAttrList);
	TreeNode * mkClassAttr (char * classAttrType, char * tString);
	TreeNode * mkMeetingList1 (TreeNode * meeting);
	TreeNode * mkMeetingList2 (TreeNode * meeting, TreeNode * meetingList);
	TreeNode * mkMeeting (TreeNode * beginMeeting, TreeNode * meetingAttrList, TreeNode * endMeeting);
	TreeNode * mkBeginMeeting (char * tOpen, char * tMeeting);
	TreeNode * mkEndMeeting (char * tSelf);
	TreeNode * mkMeetingAttrList1 (TreeNode * meetingAttr);
	TreeNode * mkMeetingAttrList2 (TreeNode * meetingAttr, TreeNode * meetingAttrList);
	TreeNode * mkMeetingAttr1 (char * tDay, TreeNode * day);
	TreeNode * mkMeetingAttr2 (char * meetingAttrType, char * tTime);
	TreeNode * mkDay(char * tDayType);
	TreeNode * mkBeginConstraint(char * tOpen, char * tConstraint, char * tClose);
	TreeNode * mkEndConstraint(char * tEnd, char * tConstraint, char * tClose);
	TreeNode * mkItemList1(TreeNode * item);
	TreeNode * mkItemList2(TreeNode * item, TreeNode * itemList);
	TreeNode * mkItem(TreeNode * beginItem,TreeNode * itemAttr, TreeNode * endItem);
	TreeNode * mkBeginItem(char * tOpen, char * tItem);
	TreeNode * mkEndItem(char * tSelf);
	TreeNode * mkItemAttr(char * itemAttrType, char * tStInt);

void PrintTree(TreeNode * );

#endif