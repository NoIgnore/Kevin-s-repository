#pragma once
#include "CLayer.h"
class CRectangle :
	public CLayer
{
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
	void SelectLayer(UINT nFlags, CPoint point);
	void Offset(CPoint ptoffset);
	CRect m_rect;
	void OnDraw(CDC* pDC);
public:
	CRectangle();
	~CRectangle();
};

