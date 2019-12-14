#include "pch.h"
#include "Cline.h"

void Cline::OnDraw(CDC* pDC)
{
	pDC->MoveTo(m_start);
	pDC->LineTo(m_end);
	if (m_type == selecting) 
	{	
		pDC->FillSolidRect(m_start.x - 3, m_start.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_end.x - 3, m_end.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
}
void Cline::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_end = point;
	m_type = normal;
}
void Cline::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_start = point;
}
void Cline::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	
	if (nFlags & MK_LBUTTON) 
	{
		pDC->SetROP2(R2_NOT);
		if (m_end.x != MAXLONG)
		{
			pDC->MoveTo(m_start);
			pDC->LineTo(m_end);
		}
		m_end = point;
		pDC->MoveTo(m_start);
		pDC->LineTo(m_end);
	}
}
void Cline::SelectLayer(UINT nFlags, CPoint point)
{
	CRect rect(m_start, m_end);
	rect.NormalizeRect();
	m_type = rect.PtInRect(point) ? selecting : normal;//Ê¹m_type±ä³Éselecting
	my_point_selected = point;
}
void Cline::Offset(CPoint ptoffset)
{
	m_start.Offset(ptoffset);
	m_end.Offset(ptoffset);
}
Cline::Cline():m_end(MAXLONG, MAXLONG),m_start(0,0)
{

}
Cline::~Cline() {

}