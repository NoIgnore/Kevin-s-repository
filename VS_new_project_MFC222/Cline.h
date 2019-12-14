#pragma once
#include "CLayer.h"
class Cline :
	public CLayer
{
	CPoint m_start, m_end;
	void OnDraw(CDC* pDC);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
public:
	
	Cline();
	~Cline();

};

