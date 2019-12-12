// Ellipse.h: interface for the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIPSE_H__CA35BA94_3CC5_4BC6_85D9_B307F954F955__INCLUDED_)
#define AFX_ELLIPSE_H__CA35BA94_3CC5_4BC6_85D9_B307F954F955__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Shape.h"

class CEllipse :virtual public CShape  
{
public:
	CEllipse();
	CEllipse(COLORREF p_borderColor,COLORREF p_fillColor,CPoint p_startPoint,CPoint p_endPoint);
	void draw(CDC* pDC);
	virtual ~CEllipse();

};

#endif // !defined(AFX_ELLIPSE_H__CA35BA94_3CC5_4BC6_85D9_B307F954F955__INCLUDED_)
