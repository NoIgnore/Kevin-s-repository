#pragma once
#include "CLayer.h"
class CEllipse :
	public CLayer
{
	CRect m_rect;
	void OnDraw(CDC* pDC);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
public:
	CEllipse();
	~CEllipse();
};

