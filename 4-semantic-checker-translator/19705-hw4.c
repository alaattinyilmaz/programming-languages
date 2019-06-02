#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "19705-hw4.h"

extern int noOfLine;
extern int lineOfCourse;
extern int lineOfClass;
extern int lineOfMeeting;
extern int courseCount;
extern int errorFlag;
extern struct CourseCheck headCourseCheck;

void prt(char * str){
    printf("%s",str); 
}

void indent(){
    printf("\t"); 
}

void newline(){
    printf("\n"); 
}

void prt2(char * str, char*str2){
    printf("%s%s",str,str2); 
}

void prt3(char * str, char*str2, char*str3){
    printf("%s%s%s",str,str2,str3); 
}

TreeNode * mkProg1 (TreeNode * elementList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = PROG1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(Prog1Node));
	ret->chosenNode->progNode1.elementList = elementList;
	return (ret);
}

TreeNode * mkProg2 ()
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = PROG2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(Prog2Node));
	ret->chosenNode->progNode2.epsilon = NULL;
	return (ret);
}

TreeNode * mkElementList1 (TreeNode * element)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ELEMENTLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ElementList1Node));
	ret->chosenNode->elementListNode1.element = element;
	return (ret);
}

TreeNode * mkElementList2 (TreeNode * element, TreeNode * elementList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ELEMENTLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ElementList2Node));
	ret->chosenNode->elementListNode2.element = element;
	ret->chosenNode->elementListNode2.elementList = elementList;
	return (ret);
}

TreeNode * mkElement1 (TreeNode * beginCourse, TreeNode * classList, TreeNode * endCourse)
{

	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ELEMENT1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(Element1Node));
	ret->chosenNode->elementNode1.beginCourse = beginCourse;
	ret->chosenNode->elementNode1.classList = classList;
	ret->chosenNode->elementNode1.endCourse = endCourse;
	return (ret);
}

TreeNode * mkElement2 (TreeNode * beginConstraint,TreeNode * itemList, TreeNode * endConstraint)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ELEMENT2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(Element2Node));
	ret->chosenNode->elementNode2.beginConstraint = beginConstraint;
	ret->chosenNode->elementNode2.itemList = itemList;
	ret->chosenNode->elementNode2.endConstraint = endConstraint;
	return (ret);
}

TreeNode * mkBeginCourse (char * tOpen , char * tCourse, TreeNode * courseAttrList, char * tClose)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = BEGINCOURSE;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(BeginCourseNode));
	ret->chosenNode->beginCourseNode.tOpen = tOpen;
	ret->chosenNode->beginCourseNode.tCourse = tCourse;
	ret->chosenNode->beginCourseNode.courseAttrList = courseAttrList;
	ret->chosenNode->beginCourseNode.tClose = tClose;
	/*
	headCourseCheck.cocc = 0;
	headCourseCheck.nocc = 0;
	headCourseCheck.tocc = 0;
	headCourseCheck.lineCount = lineOfCourse;
	*/
	return (ret);
}

/*
void printCourseCheck(){
	
		if(headCourseCheck.cocc != 1 || headCourseCheck.nocc != 1 || headCourseCheck.tocc != 1){
			errorFlag = 1;
		}

		if(headCourseCheck.cocc != 1)
		printf("ERROR: course element at line %d has %d occurrences of code\n",headCourseCheck.lineCount,headCourseCheck.cocc);
		if(headCourseCheck.nocc != 1)
		printf("ERROR: course element at line %d has %d occurrences of name\n",headCourseCheck.lineCount,headCourseCheck.cocc);
		if(headCourseCheck.tocc != 1)
		printf("ERROR: course element at line %d has %d occurrences of type\n",headCourseCheck.lineCount,headCourseCheck.tocc);
}
*/

TreeNode * mkEndCourse (char * tEnd , char * tCourse, char * tClose)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ENDCOURSE;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(EndCourseNode));
	ret->chosenNode->endCourseNode.tEnd = tEnd;
	ret->chosenNode->endCourseNode.tCourse = tCourse;
	ret->chosenNode->endCourseNode.tClose = tClose;
	//printCourseCheck();
	return (ret);
}

TreeNode * mkCourseAttrList1 (TreeNode * courseAttr)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = COURSEATTRLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(CourseAttrList1Node));
	ret->chosenNode->courseAttrList1Node.courseAttr = courseAttr;
	return (ret);
}

TreeNode * mkCourseAttrList2 (TreeNode * courseAttr, TreeNode * courseAttrList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = COURSEATTRLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(CourseAttrList2Node));
	ret->chosenNode->courseAttrList2Node.courseAttr = courseAttr;
	ret->chosenNode->courseAttrList2Node.courseAttrList = courseAttrList;
	return (ret);
}

TreeNode * mkCourseAttr (char * tCourseAttrType, char * tString)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = COURSEATTR;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(CourseAttrNode));
	ret->chosenNode->courseAttrNode.tCourseAttrType = tCourseAttrType; // TODO: WILL BE IMPROVED
	ret->chosenNode->courseAttrNode.tString = tString;
	
	char *ttype = "type=";
	char *tname = "name=";
	char *tcode = "code=";

		if(strcmp(tCourseAttrType,ttype) == 0)
		{
			headCourseCheck.tocc++;
		}
		else if(strcmp(tCourseAttrType,tname) == 0)
		{
			headCourseCheck.nocc++;
		}
		else if(strcmp(tCourseAttrType,tcode) == 0)
		{
			headCourseCheck.cocc++;
		}

	return (ret);
}

TreeNode * mkClassList1 (TreeNode * classN)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLASSLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ClassList1Node));
	ret->chosenNode->classList1Node.classN = classN;
	return (ret);
}

TreeNode * mkClassList2 (TreeNode * classN, TreeNode * classList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLASSLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ClassList2Node));
	ret->chosenNode->classList2Node.classN = classN;
	ret->chosenNode->classList2Node.classList = classList;
	return (ret);
}

TreeNode * mkClass (TreeNode * beginClass, TreeNode * classAttrList, TreeNode * endClass, TreeNode * meetingList, TreeNode * closeClass)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLASSN;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ClassNode));
	ret->chosenNode->classNode.beginClass = beginClass;
	ret->chosenNode->classNode.classAttrList = classAttrList;
	ret->chosenNode->classNode.endClass = endClass;
	ret->chosenNode->classNode.meetingList = meetingList;
	ret->chosenNode->classNode.closeClass = closeClass;
	return (ret);
}

TreeNode * mkBeginClass (char * tOpen, char * tClass)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = BEGINCLASS;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(BeginClassNode));
	ret->chosenNode->beginClassNode.tOpen = tOpen; 
	ret->chosenNode->beginClassNode.tClass = tClass; 
	return (ret);
}

TreeNode * mkEndClass (char * tClose)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ENDCLASS;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(EndClassNode));
	ret->chosenNode->endClassNode.tClose = tClose;
	return (ret);
}

TreeNode * mkCloseClass (char * tEnd, char * tClass, char * tClose)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLOSECLASS;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(CloseClassNode));
	ret->chosenNode->closeClassNode.tEnd = tEnd;
	ret->chosenNode->closeClassNode.tClass = tClass;
	ret->chosenNode->closeClassNode.tClose = tClose;
	return (ret);
}

TreeNode * mkClassAttrList1 (TreeNode * classAttr)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLASSATTRLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ClassAttrList1Node));
	ret->chosenNode->classAttrList1Node.classAttr = classAttr;
	return (ret);
}

TreeNode * mkClassAttrList2 (TreeNode * classAttr, TreeNode * classAttrList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLASSATTRLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ClassAttrList2Node));
	ret->chosenNode->classAttrList2Node.classAttr = classAttr;
	ret->chosenNode->classAttrList2Node.classAttrList = classAttrList;
	return (ret);
}

TreeNode * mkClassAttr (char * classAttrType, char * tString)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = CLASSATTR;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ClassAttrNode));
	ret->chosenNode->classAttrNode.classAttrType = classAttrType;
	ret->chosenNode->classAttrNode.tString = tString;
	return (ret);
}

TreeNode * mkMeetingList1 (TreeNode * meeting)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETINGLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingList1Node));
	ret->chosenNode->meetingList1Node.meeting = meeting;
	return (ret);
}

TreeNode * mkMeetingList2 (TreeNode * meeting, TreeNode * meetingList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETINGLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingList2Node));
	ret->chosenNode->meetingList2Node.meeting = meeting;
	ret->chosenNode->meetingList2Node.meetingList = meetingList;
	return (ret);
}

TreeNode * mkMeeting (TreeNode * beginMeeting, TreeNode * meetingAttrList, TreeNode * endMeeting)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETING;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingNode));
	ret->chosenNode->meetingNode.beginMeeting = beginMeeting;
	ret->chosenNode->meetingNode.meetingAttrList = meetingAttrList;
	ret->chosenNode->meetingNode.endMeeting = endMeeting;
	return (ret);
}

TreeNode * mkBeginMeeting (char * tOpen, char * tMeeting)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = BEGINMEETING;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(BeginMeetingNode));
	ret->chosenNode->beginMeetingNode.tOpen = tOpen;
	ret->chosenNode->beginMeetingNode.tMeeting = tMeeting;
	return (ret);
}

TreeNode * mkEndMeeting (char * tSelf)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ENDMEETING;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(EndMeetingNode));
	ret->chosenNode->endMeetingNode.tSelf = tSelf;
	return (ret);
}

TreeNode * mkMeetingAttrList1 (TreeNode * meetingAttr)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETINGATTRLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingAttrList1Node));
	ret->chosenNode->meetingAttrList1Node.meetingAttr = meetingAttr;
	return (ret);
}

TreeNode * mkMeetingAttrList2 (TreeNode * meetingAttr, TreeNode * meetingAttrList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETINGATTRLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingAttrList2Node));
	ret->chosenNode->meetingAttrList2Node.meetingAttr = meetingAttr;
	ret->chosenNode->meetingAttrList2Node.meetingAttrList = meetingAttrList;
	return (ret);
}

TreeNode * mkMeetingAttr1 (char * tDay, TreeNode * day)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETINGATTR1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingAttr1Node));
	ret->chosenNode->meetingAttr1Node.tDay = tDay;
	ret->chosenNode->meetingAttr1Node.day = day;
	return (ret);
}

TreeNode * mkMeetingAttr2 (char * meetingAttrType, char * tTime)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = MEETINGATTR2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(MeetingAttr2Node));
	ret->chosenNode->meetingAttr2Node.meetingAttrType = meetingAttrType;
	ret->chosenNode->meetingAttr2Node.tTime = tTime;
	return (ret);
}

TreeNode * mkDay(char * tDayType)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = DAY;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(DayNode));
	ret->chosenNode->dayNode.tDayType = tDayType;
	return (ret);
}

TreeNode * mkBeginConstraint(char * tOpen, char * tConstraint, char * tClose)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = BEGINCONSTRAINT;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(BeginConstraintNode));
	ret->chosenNode->beginConstraintNode.tOpen = tOpen;
	ret->chosenNode->beginConstraintNode.tConstraint = tConstraint;
	ret->chosenNode->beginConstraintNode.tClose= tClose;
	return (ret);
}

TreeNode * mkEndConstraint(char * tEnd, char * tConstraint, char * tClose)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ENDCONSTRAINT;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(EndConstraintNode));
	ret->chosenNode->endConstraintNode.tEnd = tEnd;
	ret->chosenNode->endConstraintNode.tConstraint = tConstraint;
	ret->chosenNode->endConstraintNode.tClose= tClose;
	return (ret);
}

TreeNode * mkItemList1(TreeNode * item)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ITEMLIST1;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ItemList1Node));
	ret->chosenNode->itemList1Node.item = item;
	return (ret);
}

TreeNode * mkItemList2(TreeNode * item, TreeNode * itemList)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ITEMLIST2;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ItemList2Node));
	ret->chosenNode->itemList2Node.item = item;
	ret->chosenNode->itemList2Node.itemList = itemList;
	return (ret);
}

TreeNode * mkItem(TreeNode * beginItem,TreeNode * itemAttr, TreeNode * endItem)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ITEM;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ItemNode));
	ret->chosenNode->itemNode.beginItem = beginItem;
	ret->chosenNode->itemNode.itemAttr = itemAttr;
	ret->chosenNode->itemNode.endItem = endItem;
	return (ret);
}

TreeNode * mkBeginItem(char * tOpen, char * tItem)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = BEGINITEM;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(BeginItemNode));
	ret->chosenNode->beginItemNode.tOpen = tOpen;
	ret->chosenNode->beginItemNode.tItem = tItem;
	return (ret);
}

TreeNode * mkEndItem(char * tSelf)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ENDITEM;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(EndItemNode));
	ret->chosenNode->endItemNode.tSelf = tSelf;
	return (ret);
}

TreeNode * mkItemAttr(char * itemAttrType, char * tStInt)
{
	TreeNode * ret = (TreeNode *)malloc (sizeof(TreeNode));
	ret->nodeType = ITEMATTR;
	ret->chosenNode = (union ChosenNode *)malloc (sizeof(ItemAttrNode));
	ret->chosenNode->itemAttrNode.itemAttrType = itemAttrType;
	ret->chosenNode->itemAttrNode.tStInt = tStInt;
	return (ret);
}

void PrintTree(TreeNode * ptr){

	if(ptr->nodeType == PROG1)
	{
		PrintTree(ptr->chosenNode->progNode1.elementList);
	}
	
	if(ptr->nodeType == ELEMENTLIST1)
	{
		PrintTree(ptr->chosenNode->elementListNode1.element);
	}
	
	if(ptr->nodeType == ELEMENTLIST2)
	{
		if(ptr->chosenNode->elementListNode2.element->nodeType == ELEMENT2)
		{
			PrintTree(ptr->chosenNode->elementListNode2.elementList);
			PrintTree(ptr->chosenNode->elementListNode2.element);
		}
		else {
			PrintTree(ptr->chosenNode->elementListNode2.element);
			PrintTree(ptr->chosenNode->elementListNode2.elementList);
		}
	}
	
	if(ptr->nodeType == ELEMENT1)
	{
		PrintTree(ptr->chosenNode->elementNode1.beginCourse);
		PrintTree(ptr->chosenNode->elementNode1.classList);
		PrintTree(ptr->chosenNode->elementNode1.endCourse);
	}
	
	if(ptr->nodeType == ELEMENT2)
	{
		PrintTree(ptr->chosenNode->elementNode2.beginConstraint);
		PrintTree(ptr->chosenNode->elementNode2.itemList);
		PrintTree(ptr->chosenNode->elementNode2.endConstraint);
	}
	
	if(ptr->nodeType == BEGINCOURSE)
	{
		char * tOpen = ptr->chosenNode->beginCourseNode.tOpen;
		char * tCourse = ptr->chosenNode->beginCourseNode.tCourse;
		prt2(tOpen,tCourse);
		PrintTree(ptr->chosenNode->beginCourseNode.courseAttrList);
		char * tClose = ptr->chosenNode->beginCourseNode.tClose;
		prt(tClose);
		newline();
	}

	if(ptr->nodeType == ENDCOURSE)
	{
		char * tEnd = ptr->chosenNode->endCourseNode.tEnd;
		char * tCourse = ptr->chosenNode->endCourseNode.tCourse;
		char * tClose = ptr->chosenNode->endCourseNode.tClose;
		prt3(tEnd,tCourse,tClose);
		newline();
	}

	
	if(ptr->nodeType == COURSEATTRLIST1)
	{
		PrintTree(ptr->chosenNode->courseAttrList1Node.courseAttr);
	}
	
	if(ptr->nodeType == COURSEATTRLIST2)
	{
		PrintTree(ptr->chosenNode->courseAttrList2Node.courseAttr);
		PrintTree(ptr->chosenNode->courseAttrList2Node.courseAttrList);
	}
	
	if(ptr->nodeType == COURSEATTR)
	{
		///// NEED TO BE HANDLED //////
		char * tCourseAttrType = ptr->chosenNode->courseAttrNode.tCourseAttrType;
		char * tString = ptr->chosenNode->courseAttrNode.tString;
		printf(" ");
		prt2(tCourseAttrType,tString);
	}
	
	if(ptr->nodeType == CLASSLIST1)
	{
		PrintTree(ptr->chosenNode->classList1Node.classN);
	}
	
	if(ptr->nodeType == CLASSLIST2)
	{
		PrintTree(ptr->chosenNode->classList2Node.classN);
		PrintTree(ptr->chosenNode->classList2Node.classList);
	}
	
	if(ptr->nodeType == CLASSN)
	{
		PrintTree(ptr->chosenNode->classNode.beginClass);
		PrintTree(ptr->chosenNode->classNode.classAttrList);
		PrintTree(ptr->chosenNode->classNode.endClass);
		PrintTree(ptr->chosenNode->classNode.meetingList);
		PrintTree(ptr->chosenNode->classNode.closeClass);
	}
	
	if(ptr->nodeType == BEGINCLASS)
	{
		char * tOpen = ptr->chosenNode->beginClassNode.tOpen;
		char * tClass = ptr->chosenNode->beginClassNode.tClass;
		indent();
		prt2(tOpen,tClass);
	}

	if(ptr->nodeType == ENDCLASS)
	{
		char * tClose = ptr->chosenNode->endClassNode.tClose;
		prt(tClose);
		newline();
	}
		
	if(ptr->nodeType == CLOSECLASS)
	{
		char * tEnd = ptr->chosenNode->closeClassNode.tEnd;
		char * tClass = ptr->chosenNode->closeClassNode.tClass;
		char * tClose = ptr->chosenNode->closeClassNode.tClose;
		indent();
		prt3(tEnd,tClass,tClose);
		newline();
	}
	
	if(ptr->nodeType == CLASSATTRLIST1)
	{
		PrintTree(ptr->chosenNode->classAttrList1Node.classAttr);
	}
	/// PROBLEM !!
	if(ptr->nodeType == CLASSATTRLIST2)
	{
		PrintTree(ptr->chosenNode->classAttrList2Node.classAttr);
		PrintTree(ptr->chosenNode->classAttrList2Node.classAttrList);
	}

	if(ptr->nodeType == CLASSATTR)
	{
		char * classAttrType = ptr->chosenNode->classAttrNode.classAttrType;
		char * tString = ptr->chosenNode->classAttrNode.tString;
		printf(" ");
		prt2(classAttrType,tString);
	}
	
	if(ptr->nodeType == MEETINGLIST1)
	{
		PrintTree(ptr->chosenNode->meetingList1Node.meeting);
	}

	if(ptr->nodeType == MEETINGLIST2)
	{
		PrintTree(ptr->chosenNode->meetingList2Node.meeting);
		PrintTree(ptr->chosenNode->meetingList2Node.meetingList);
	}
	
	if(ptr->nodeType == MEETING)
	{	
		PrintTree(ptr->chosenNode->meetingNode.beginMeeting);
		PrintTree(ptr->chosenNode->meetingNode.meetingAttrList);
		PrintTree(ptr->chosenNode->meetingNode.endMeeting);
	}	
	
	if(ptr->nodeType == BEGINMEETING)
	{	
		char * tOpen = ptr->chosenNode->beginMeetingNode.tOpen;
		char * tMeeting = ptr->chosenNode->beginMeetingNode.tMeeting;
		indent();
		indent();
		prt2(tOpen,tMeeting);
	}
	
	if(ptr->nodeType == ENDMEETING)
	{	
		char * tSelf = ptr->chosenNode->endMeetingNode.tSelf;
		prt(tSelf);
		newline();
	}
	
	if(ptr->nodeType == MEETINGATTRLIST1)
	{	
		PrintTree(ptr->chosenNode->meetingAttrList1Node.meetingAttr);
	}

	if(ptr->nodeType == MEETINGATTRLIST2)
	{	
		PrintTree(ptr->chosenNode->meetingAttrList2Node.meetingAttr);
		PrintTree(ptr->chosenNode->meetingAttrList2Node.meetingAttrList);
	}
	
	if(ptr->nodeType == MEETINGATTR1)
	{	
		char * tDay = ptr->chosenNode->meetingAttr1Node.tDay;
		printf(" ");
		prt(tDay);
		PrintTree(ptr->chosenNode->meetingAttr1Node.day);
	}

	if(ptr->nodeType == MEETINGATTR2)
	{	
		char * meetingAttrType = ptr->chosenNode->meetingAttr2Node.meetingAttrType;
		char * tTime = ptr->chosenNode->meetingAttr2Node.tTime;
		printf(" ");
		prt2(meetingAttrType,tTime);
	}
	
	if(ptr->nodeType == DAY)
	{	
		char * tDay = ptr->chosenNode->dayNode.tDayType;
		prt(tDay);
	}
	
	if(ptr->nodeType == BEGINCONSTRAINT)
	{	
		char * tOpen = ptr->chosenNode->beginConstraintNode.tOpen;
		char * tConstraint = ptr->chosenNode->beginConstraintNode.tConstraint;
		char * tClose = ptr->chosenNode->beginConstraintNode.tClose;
		prt3(tOpen,tConstraint,tClose);
		newline();
	}

	if(ptr->nodeType == ENDCONSTRAINT)
	{	
		char * tEnd = ptr->chosenNode->endConstraintNode.tEnd;
		char * tConstraint = ptr->chosenNode->endConstraintNode.tConstraint;
		char * tClose = ptr->chosenNode->endConstraintNode.tClose;
		prt3(tEnd,tConstraint,tClose);
		newline();
	}

	if(ptr->nodeType == ITEMLIST1)
	{	
		PrintTree(ptr->chosenNode->itemList1Node.item);
	}
	
	if(ptr->nodeType == ITEMLIST2)
	{	
		PrintTree(ptr->chosenNode->itemList2Node.item);
		PrintTree(ptr->chosenNode->itemList2Node.itemList);
	}

	if(ptr->nodeType == ITEM)
	{	
		PrintTree(ptr->chosenNode->itemNode.beginItem);
		PrintTree(ptr->chosenNode->itemNode.itemAttr);
		PrintTree(ptr->chosenNode->itemNode.endItem);
	}

	if(ptr->nodeType == ITEM)
	{	
		PrintTree(ptr->chosenNode->itemNode.beginItem);
		PrintTree(ptr->chosenNode->itemNode.itemAttr);
		PrintTree(ptr->chosenNode->itemNode.endItem);
	}
		
	if(ptr->nodeType == BEGINITEM)
	{	
		char * tOpen = ptr->chosenNode->beginItemNode.tOpen;
		char * tItem = ptr->chosenNode->beginItemNode.tItem;
		indent();
		prt2(tOpen,tItem);
	}
	
	if(ptr->nodeType == ENDITEM)
	{	
		char * tSelf = ptr->chosenNode->endItemNode.tSelf;
		prt(tSelf);
		newline();
	}

	if(ptr->nodeType == ITEMATTR)
	{	
		char * itemAttrType = ptr->chosenNode->itemAttrNode.itemAttrType;
		char * tStInt = ptr->chosenNode->itemAttrNode.tStInt;
		printf(" ");
		prt2(itemAttrType,tStInt);
	}
	

}