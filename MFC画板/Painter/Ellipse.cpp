// Ellipse.cpp: implementation of the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Ellipse.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEllipse::CEllipse()
{
	setShapeType(ELLIPSE);
}
CEllipse::CEllipse(COLORREF p_borderColor,
	  COLORREF p_fillColor,
	  CPoint p_startPoint,
	  CPoint p_endPoint):
	CShape(p_borderColor,p_fillColor,p_startPoint,p_endPoint)
{
	setShapeType(ELLIPSE);
}

//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CEllipse::draw(CDC* pDC)
{
		//������ʱ���ʣ����ڱ߿���ɫ
		CPen pen;
		pen.CreatePen(PS_SOLID,1,borderColor);
		pDC->SelectObject(&pen);//�ѻ���ѡ���豸
		//������ʱ��ˢ�����������ɫ
		CBrush brush;
		brush.CreateSolidBrush(fillColor);
		pDC->SelectObject(&brush);
		//����
		pDC->Ellipse(startPoint.x,startPoint.y,endPoint.x,endPoint.y);
		//ɾ����ʱ����
		pen.DeleteObject();
		brush.DeleteObject(); 

}
CEllipse::~CEllipse()
{

}
