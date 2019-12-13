// Shape.cpp: implementation of the CShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CShape::CShape():
	borderColor(RGB(0,0,0)),//默认黑色
	fillColor(RGB(255,255,255)),//默认白色
	startPoint(100,100),//无关紧要的默认值
	endPoint(200,200),
	type(UNSURE)
{
	
}

CShape::CShape(COLORREF p_borderColor,
			   COLORREF p_fillColor,
			   CPoint p_startPoint,
			   CPoint p_endPoint):
	borderColor(p_borderColor),
	fillColor(p_fillColor),
	startPoint(p_startPoint),
	endPoint(p_endPoint),
	type(UNSURE)
{
	
}



CShape::~CShape()
{

}
