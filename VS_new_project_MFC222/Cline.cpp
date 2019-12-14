#include "pch.h"
#include "Cline.h"

void Cline::OnDraw(CDC* pDC)
{
	pDC->MoveTo(m_start);
	pDC->LineTo(m_end);
}
void Cline::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_end = point;
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
Cline::Cline():m_end(MAXLONG, MAXLONG),m_start(0,0)
{

}
Cline::~Cline() {

}