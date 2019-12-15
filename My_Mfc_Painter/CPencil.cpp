#include "pch.h"
#include "CPencil.h"

void CPencil::OnDraw(CDC* pDC)
{
	int nSize = m_pencil.GetSize();
	int i = 0;
	if (nSize <= 0)return;
	pDC->MoveTo(m_pencil[i++]);
	while (i < nSize) {
		pDC->LineTo(m_pencil[i++]);
	}
	if (m_type == selecting) {
		CPoint& ps = m_pencil[0];
		pDC->FillSolidRect(ps.x - 3, ps.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		CPoint& pe = m_pencil[nSize-1];
		pDC->FillSolidRect(pe.x - 3, pe.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
}

void CPencil::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pencil.Add(point);
	m_type = normal;
}

void CPencil::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_pencil.Add(point);
	m_shape = 0;
}

void CPencil::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	if (nFlags & MK_LBUTTON) {
		int nSize = m_pencil.GetSize();
		if (nSize <= 0) {
			return;
		}
		CPoint pt = m_pencil[nSize - 1];
		int cx = pt.x - point.x;
		int cy = pt.y - point.y;
		if (sqrt(cx * cx + cy * cy) < 5) {
			return;
		}
		pDC->MoveTo(pt);
		m_pencil.Add(point);
		pDC->LineTo(point);
	}
}

void CPencil::SelectLayer(UINT nFlags, CPoint point)
{
	int i=0,nSize = m_pencil.GetSize();
	while (i<nSize)
	{
		CPoint &pt = m_pencil[i++];
		int cx = pt.x - point.x;
		int cy = pt.y - point.y;
		if (sqrt(cx * cx + cy * cy) < 8) {
			m_type = selecting;
			my_point_selected = point;
			return;
		}
	}
	m_type = normal;
}

void CPencil::Offset(CPoint ptoffset)
{
	int i = 0, nSize = m_pencil.GetSize();
	while (i < nSize)
	{
		m_pencil[i++].Offset(ptoffset);
	}
}

CPencil::CPencil()
{
}

CPencil::~CPencil()
{
}
