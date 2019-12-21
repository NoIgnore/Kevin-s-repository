#pragma once
#include "CLayer.h"
class CRectangle :
	public CLayer
{
	CRect m_rect;
	CPoint m_lefttop, m_rightbotton;
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
	void SelectLayer(UINT nFlags, CPoint point);
	void Offset(CPoint ptoffset);
	void OnDraw(CDC* pDC);
	void OnFileSave();
	void OnFileOpen(CString pathName);
public:
	CRectangle();
	~CRectangle();
};

