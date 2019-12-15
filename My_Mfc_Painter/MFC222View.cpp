
// MFC222View.cpp: CMFC222View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC222.h"
#endif

#include "MFC222Doc.h"
#include "MFC222View.h"

#include "Cline.h"
#include"CEllipse.h"
#include"CRectangle.h"
#include "CPencil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC222View

IMPLEMENT_DYNCREATE(CMFC222View, CView)

BEGIN_MESSAGE_MAP(CMFC222View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_ARROW, &CMFC222View::OnDrawArrow)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ARROW, &CMFC222View::OnUpdateDrawArrow)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CMFC222View::OnDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CMFC222View::OnUpdateDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, &CMFC222View::OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CMFC222View::OnUpdateDrawLine)
	ON_COMMAND(ID_DRAW_RECT, &CMFC222View::OnDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CMFC222View::OnUpdateDrawRect)
	ON_COMMAND(ID_DRAW_PENCIL, &CMFC222View::OnDrawPencil)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PENCIL, &CMFC222View::OnUpdateDrawPencil)
//	ON_COMMAND(ID_FILE_SAVE, &CMFC222View::OnFileSave)
//	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, &CMFC222View::OnUpdateFileSave)
END_MESSAGE_MAP()

// CMFC222View 构造/析构

CMFC222View::CMFC222View()
{
	// TODO: 在此处添加构造代码
	m_nIndex = ID_DRAW_ARROW;
}

void CMFC222View::SelectLayer(UINT nFlags, CPoint point)
{
	/*CMFC222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);*/

	int i = 0, nSize = m_ls.GetSize();
	while (i < nSize) {
		m_ls[i++]->SelectLayer(nFlags, point);
	}

	/*int k = 0, l = pDoc->shapes.size();
	while (k < l)
	{
		pDoc->shapes[k++]->SelectLayer(nFlags, point);
	}*/
	Invalidate(true);
}

void CMFC222View::SelectEnd(UINT nFlags, CPoint point)
{
	CMFC222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CLayer* player = NULL;
	CLayer* player2 = NULL;
	int i = 0, nSize = m_ls.GetSize();
	while (i < nSize) 
	{
		player2 = pDoc->shapes[i];
		player = m_ls[i++];
		if (player->m_type == CLayer::selecting) 
		{
			player->Offset(point - player->my_point_selected);
			player2->Offset(point - player->my_point_selected);
		}
	}

	/*int k = 0, l = pDoc->shapes.size();
	while (k < l)
	{
		player = pDoc->shapes[k++];
		if (player->m_type == CLayer::selecting)
		{
			player->Offset(point - player->my_point_selected);
		}
	}*/

	Invalidate(TRUE);
}

CMFC222View::~CMFC222View()
{
	int i = 0, nSize = m_ls.GetSize();
	while (i < nSize) {
		delete m_ls[i++];
	}
}

BOOL CMFC222View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC222View 绘图

void CMFC222View::OnDraw(CDC* pDC)
{
	CMFC222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)return;
	if (pDoc->numberdoc == 1)
	{
		pDoc->draw(pDC);
		pDoc->numberdoc = 0;
		//Invalidate();//???加不加?no!
	
		int n = pDoc->shapes.size();
		for (int i = 0; i < n; i++)
		{
			pDoc->shapes[i]->read_file_o = 1;
			m_ls.Add(pDoc->shapes[i]);
		}
	}
	int i = 0, nSize = m_ls.GetSize();
	while (i<nSize)
	{
		m_ls[i]->OnDraw(pDC);
		++i;
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC222View 打印

BOOL CMFC222View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC222View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC222View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC222View 诊断

#ifdef _DEBUG
void CMFC222View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC222View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC222Doc* CMFC222View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC222Doc)));
	return (CMFC222Doc*)m_pDocument;
}
#endif //_DEBUG

// CMFC222View 消息处理程序

void CMFC222View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CView::OnLButtonDown(nFlags, point);
	if (ID_DRAW_ARROW == m_nIndex )
	{
		SelectLayer(nFlags, point);

		/*CMFC222Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->SelectLayer(nFlags, point);*/

		return;
	}
	CLayer* player = NULL;
	switch (m_nIndex)
	{
	case ID_DRAW_LINE:
		player = new Cline;
		break;

	case ID_DRAW_ELLIPSE:
		player = new CEllipse;
		break;

	case ID_DRAW_RECT:
		player = new CRectangle;
		break;

	
	case ID_DRAW_PENCIL:
		player = new CPencil;
		break;
	}
	if (player)
	{
		player->OnLButtonDown(nFlags, point);
		m_ls.Add(player);
	
		CMFC222Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->push_back(player);
	}



}


void CMFC222View::OnLButtonUp(UINT nFlags, CPoint point)
{

	CView::OnLButtonUp(nFlags, point);
	if (ID_DRAW_ARROW == m_nIndex)
	{
		SelectEnd(nFlags, point);

		/*CMFC222Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->SelectEnd(nFlags, point);*/

		return;
	}
	int nSize = m_ls.GetSize();
	if (!nSize)return;
	m_ls[nSize-1]->OnLButtonUp(nFlags, point);
	CMFC222Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->setEndPoint(point);
	Invalidate(FALSE);

}


void CMFC222View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (ID_DRAW_ARROW == m_nIndex) 
	{
		return;
	}
	CView::OnMouseMove(nFlags, point);
	int nSize = m_ls.GetSize();
	if (nSize<=0)return;
	CClientDC dc(this);
	m_ls[nSize - 1]->OnMouseMove(nFlags, point, &dc);
	Invalidate(FALSE);

}


void CMFC222View::OnDrawArrow()
{
	// TODO: 在此添加命令处理程序代码
	m_nIndex = ID_DRAW_ARROW;
}


void CMFC222View::OnUpdateDrawArrow(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nIndex == ID_DRAW_ARROW);
}


void CMFC222View::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_nIndex = ID_DRAW_ELLIPSE;
}


void CMFC222View::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nIndex == ID_DRAW_ELLIPSE);
}


void CMFC222View::OnDrawLine()
{
	m_nIndex = ID_DRAW_LINE;
}


void CMFC222View::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nIndex == ID_DRAW_LINE);
}


void CMFC222View::OnDrawRect()
{
	m_nIndex = ID_DRAW_RECT;
}


void CMFC222View::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nIndex == ID_DRAW_RECT);
}


void CMFC222View::OnDrawPencil()
{
	m_nIndex = ID_DRAW_PENCIL;
}


void CMFC222View::OnUpdateDrawPencil(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nIndex == ID_DRAW_PENCIL);
}

