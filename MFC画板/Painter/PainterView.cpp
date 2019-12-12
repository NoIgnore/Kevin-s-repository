// PainterView.cpp : implementation of the CPainterView class
//

#include "stdafx.h"
#include "Painter.h"

#include "PainterDoc.h"
#include "PainterView.h"

//��״ͷ�ļ�
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPainterView

IMPLEMENT_DYNCREATE(CPainterView, CView)

BEGIN_MESSAGE_MAP(CPainterView, CView)
	//{{AFX_MSG_MAP(CPainterView)
	ON_COMMAND(ID_SHAPE_LINE, OnShapeLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SHAPE_RECTANGLE, OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_ELLIPSE, OnShapeEllipse)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_FILLCOLOR_BLACK, OnFillcolorBlack)
	ON_COMMAND(ID_FILLCOLOR_BLUE, OnFillcolorBlue)
	ON_COMMAND(ID_FILLCOLOR_GREEN, OnFillcolorGreen)
	ON_COMMAND(ID_FILLCOLOR_RED, OnFillcolorRed)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_LINE, OnUpdateShapeLine)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_RECTANGLE, OnUpdateShapeRectangle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_ELLIPSE, OnUpdateShapeEllipse)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_FILLCOLOR_BLACK, OnUpdateFillcolorBlack)
	ON_UPDATE_COMMAND_UI(ID_FILLCOLOR_BLUE, OnUpdateFillcolorBlue)
	ON_UPDATE_COMMAND_UI(ID_FILLCOLOR_GREEN, OnUpdateFillcolorGreen)
	ON_UPDATE_COMMAND_UI(ID_FILLCOLOR_RED, OnUpdateFillcolorRed)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_COMMAND(ID_FILLCOLOR_WHITE, OnFillcolorWhite)
	ON_UPDATE_COMMAND_UI(ID_FILLCOLOR_WHITE, OnUpdateFillcolorWhite)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPainterView construction/destruction

CPainterView::CPainterView():
	m_borderColor(RGB(0,0,0)),//��ɫ
	m_fillColor(RGB(255,255,255)),//��ɫ
	m_shapeType(LINE),//ֱ��
	m_drawState(0)
{
	// TODO: add construction code here

}

CPainterView::~CPainterView()
{
}

BOOL CPainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPainterView drawing

void CPainterView::OnDraw(CDC* pDC)
{
	CPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDoc->draw(pDC);//����ͼ��


	/*/test==========//
	CString s;
	s.Format("%d",pDoc->size());
	pDC->TextOut(0,0,s);
	//test==========/*/
}

/////////////////////////////////////////////////////////////////////////////
// CPainterView printing

BOOL CPainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPainterView diagnostics

#ifdef _DEBUG
void CPainterView::AssertValid() const
{
	CView::AssertValid();
}

void CPainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPainterDoc* CPainterView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPainterDoc)));
	return (CPainterDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPainterView message handlers

void CPainterView::OnShapeLine() 
{
	// TODO: Add your command handler code here
	m_shapeType=LINE;
}

void CPainterView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	
	m_drawState=1;//��ʼ��ͼ
	
	CShape* newShape=NULL;//����״
	switch(m_shapeType)
	{
	case LINE://ֱ��
		newShape=new CLine(m_borderColor,m_fillColor,point,point);
		//�յ�δ��
	
		break;
	case RECTANGLE://����
		newShape=new CRectangle(m_borderColor,m_fillColor,point,point);
	
		break;
	case ELLIPSE:
		newShape=new CEllipse(m_borderColor,m_fillColor,point,point);
	
		break;
	}

	//��ȡ�ĵ�ָ���Դ�������
	CPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->push_back(newShape);

}

void CPainterView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);


	m_drawState=0;//������ͼ
	//��ȡ�ĵ�ָ���Դ�������
	CPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDoc->setEndPoint(point);
	Invalidate();//���ͻ�����Ч��������ˢ��
}

void CPainterView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);

	static int refreshFlag=0;//��ֹˢ�¹��������˸
	int time=256;//refreshFlag��ѭ�����ڣ�����Ӱ��ˢ��Ƶ��
	int interval=5;//ÿinterval�ε��ô˺�����ˢ��һ��
	if(m_drawState==1)//ֻ�ڻ滭����ˢ�£�������˸
	{
		CPainterDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->setEndPoint(point);
		if(refreshFlag>=time)
		{
			refreshFlag=0;//ѭ��
		}
		if(refreshFlag%interval==0)
		{
			Invalidate();
		}
		refreshFlag++;
		
	}
}

void CPainterView::OnShapeRectangle() 
{
	// TODO: Add your command handler code here
	m_shapeType=RECTANGLE;
}

void CPainterView::OnShapeEllipse() 
{
	// TODO: Add your command handler code here
	m_shapeType=ELLIPSE;
}

void CPainterView::OnColorBlack() 
{
	// TODO: Add your command handler code here
	m_borderColor=RGB(0,0,0);
}

void CPainterView::OnColorBlue() 
{
	// TODO: Add your command handler code here
	m_borderColor=RGB(0,0,255);
}

void CPainterView::OnColorGreen() 
{
	// TODO: Add your command handler code here
	m_borderColor=RGB(0,255,0);
}

void CPainterView::OnColorRed() 
{
	// TODO: Add your command handler code here
	m_borderColor=RGB(255,0,0);
}

void CPainterView::OnFillcolorBlack() 
{
	// TODO: Add your command handler code here
	m_fillColor=RGB(0,0,0);
}

void CPainterView::OnFillcolorBlue() 
{
	// TODO: Add your command handler code here
	m_fillColor=RGB(0,0,255);
}

void CPainterView::OnFillcolorGreen() 
{
	// TODO: Add your command handler code here
	m_fillColor=RGB(0,255,0);
}

void CPainterView::OnFillcolorRed() 
{
	// TODO: Add your command handler code here
	m_fillColor=RGB(255,0,0);
}

void CPainterView::OnUpdateShapeLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_shapeType==LINE)
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}

	
}

void CPainterView::OnUpdateShapeRectangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_shapeType==RECTANGLE)
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateShapeEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_shapeType==ELLIPSE)
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
	
}

void CPainterView::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_borderColor==RGB(0,0,0))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_borderColor==RGB(0,0,255))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_borderColor==RGB(0,255,0))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_borderColor==RGB(255,0,0))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateFillcolorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_fillColor==RGB(0,0,0))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateFillcolorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_fillColor==RGB(0,0,255))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateFillcolorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_fillColor==RGB(0,255,0))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnUpdateFillcolorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_fillColor==RGB(255,0,0))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}

void CPainterView::OnEditUndo() 
{
	// TODO: Add your command handler code here
	CPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(!pDoc->empty())
	{

		pDoc->pop_back();//ɾ����һ�����Ƶ�ͼ��
		Invalidate();
	}
	
}

void CPainterView::OnClear() 
{
	// TODO: Add your command handler code here
	CPainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->clear();
	Invalidate();
}

void CPainterView::OnFillcolorWhite() 
{
	// TODO: Add your command handler code here
	m_fillColor=RGB(255,255,255);
}

void CPainterView::OnUpdateFillcolorWhite(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_fillColor==RGB(255,255,255))
	{
		pCmdUI->SetCheck(true);
	}
	else
	{
		pCmdUI->SetCheck(false);
	}
}
