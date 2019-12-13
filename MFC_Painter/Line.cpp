// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{
	setShapeType(LINE);
}
CLine::CLine(COLORREF p_borderColor,
	  COLORREF p_fillColor,
	  CPoint p_startPoint,
	  CPoint p_endPoint):
	CShape(p_borderColor,p_fillColor,p_startPoint,p_endPoint)
{
	setShapeType(LINE);
}

//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CLine :: draw(CDC* pDC)
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
		pDC->MoveTo(startPoint);
		pDC->LineTo(endPoint);
		//ɾ����ʱ����
		pen.DeleteObject();
		brush.DeleteObject(); 

}
CLine::~CLine()
{

}
